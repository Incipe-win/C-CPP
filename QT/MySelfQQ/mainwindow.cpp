#include "mainwindow.h"
#include <QColorDialog>
#include <QDataStream>
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString name) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  udpSocket = new QUdpSocket(this);

  uName = name;

  this->port = 9999;

  udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
  sndMsg(UsrEnter);
  connect(ui->sendBtn, &QPushButton::clicked, [=]() { sndMsg(Msg); });

  connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::ReceiveMessage);

  // 点击退出
  connect(ui->exitBtn, &QPushButton::clicked, [=]() { this->close(); });

  //////////////////////////////辅助功能////////////////////////////
  //字体
  connect(ui->frontCbx, &QFontComboBox::currentFontChanged, [=](const QFont &font) {
    ui->msgTxtEdit->setCurrentFont(font);
    ui->msgTxtEdit->setFocus();
  });

  //字号
  void (QComboBox::*cbxsingal)(const QString &text) = &QComboBox::currentIndexChanged;
  connect(ui->sizeCbx, cbxsingal, [=](const QString &text) {
    ui->msgTxtEdit->setFontPointSize(text.toDouble());
    ui->msgTxtEdit->setFocus();
  });

  //加粗
  connect(ui->blodTBtn, &QToolButton::clicked, [=](bool isCheck) {
    if (isCheck) {
      ui->msgTxtEdit->setFontWeight(QFont::Bold);
    } else {
      ui->msgTxtEdit->setFontWeight(QFont::Normal);
    }
  });

  //倾斜
  connect(ui->italicTBtn, &QToolButton::clicked, [=](bool check) { ui->msgTxtEdit->setFontItalic(check); });

  //下划线
  connect(ui->underlineTBtn, &QToolButton::clicked, [=](bool check) { ui->msgTxtEdit->setFontUnderline(check); });

  //字体颜色
  connect(ui->colorTBtn, &QToolButton::clicked, [=]() {
    QColor color = QColorDialog::getColor(Qt::red);
    ui->msgTxtEdit->setTextColor(color);
  });

  //清空聊天记录
  connect(ui->clearTBtn, &QToolButton::clicked, [=]() { ui->msgBrowser->clear(); });

  //保存聊天记录
  connect(ui->saveTBtn, &QToolButton::clicked, [=]() {
    if (ui->msgBrowser->document()->isEmpty()) {
      QMessageBox::warning(this, "警告", "内容不能为空");
      return;

    } else {
      QString path = QFileDialog::getSaveFileName(this, "保存记录", "聊天记录", "(*.txt)");
      QFile file(path);
      //打开模式加换行操作
      file.open(QIODevice::WriteOnly | QIODevice::Text);
      QTextStream stream(&file);
      stream << ui->msgBrowser->toPlainText();
      file.close();
    }
  });
}

void MainWindow::ReceiveMessage() {
  // 拿数据报文
  qint64 size = udpSocket->pendingDatagramSize();

  QByteArray array = QByteArray(10000, 0);
  udpSocket->readDatagram(array.data(), size);
  // 解析数据
  // 第一段类型， 第二段用户名， 第三段数据
  QDataStream stream(&array, QIODevice::ReadOnly);
  int msgType;  // 读取类型
  QString usrName;
  QString msg;

  // 获取当前时间
  QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
  stream >> msgType;
  switch (msgType) {
    case Msg: {
      stream >> usrName >> msg;
      // 追加聊天记录
      ui->msgBrowser->setTextColor(Qt::blue);
      ui->msgBrowser->append("[" + usrName + "]" + time);
      ui->msgBrowser->append(msg);
      break;
    }
    case UsrEnter: {
      stream >> usrName;
      usrEnter(usrName);
      break;
    }
    case UsrLeft: {
      stream >> usrName;
      usrLeft(usrName, time);
      break;
    }
    default: {
      break;
    }
  }
}

void MainWindow::usrLeft(QString usrname, QString time) {
  // 更新群成员
  bool isEmpty = ui->usrTblWidget->findItems(usrname, Qt::MatchExactly).isEmpty();
  if (!isEmpty) {
    int row = ui->usrTblWidget->findItems(usrname, Qt::MatchExactly).first()->row();
    ui->usrTblWidget->removeRow(row);

    // 追加聊天记录
    ui->msgBrowser->setTextColor(Qt::gray);
    ui->msgBrowser->append(QString("%1 于 %2 离开").arg(usrname, time));

    ui->usrNumLbl->setText(QString("在线用户：%1人").arg(ui->usrTblWidget->rowCount()));
    //    sndMsg(UsrLeft);
  }
}

void MainWindow::usrEnter(QString username) {
  bool isEmpty = ui->usrTblWidget->findItems(username, Qt::MatchExactly).isEmpty();
  if (isEmpty) {
    // 更新群成员
    QTableWidgetItem *usr = new QTableWidgetItem(username);
    ui->usrTblWidget->insertRow(0);
    ui->usrTblWidget->setItem(0, 0, usr);
    // 追加聊天记录
    ui->msgBrowser->setTextColor(Qt::gray);
    ui->msgBrowser->append(QString("%1上线了").arg(username));
    // 更新在线人数
    ui->usrNumLbl->setText(QString("在线用户：%1人").arg(ui->usrTblWidget->rowCount()));
    // 把自身信息广播出去
    sndMsg(UsrEnter);
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::sndMsg(MsgType type) {
  // 消息分为三类
  // 发送数据分段处理 第一段 类型 第二段 用户名 第三段 具体内容
  QByteArray array;
  QDataStream stream(&array, QIODevice::WriteOnly);
  stream << type << getUsr();  // 第一, 二段添加到流
  switch (type) {
      // 普通消息
    case Msg:
      // 如果没有输入内容， 不发任何消息
      if (ui->msgTxtEdit->toPlainText() == "") {
        QMessageBox::warning(this, "警告", "发送内容不能为空");
        return;
      }
      // 内容
      stream << getMsg();
      break;
      // 用户进入消息
    case UsrEnter:
      break;
      // 用户离开消息
    case UsrLeft:
      break;
    default:
      break;
  }
  udpSocket->writeDatagram(array, QHostAddress::Broadcast, port);
}

QString MainWindow::getUsr() { return this->uName; }

QString MainWindow::getMsg() {
  QString str = ui->msgTxtEdit->toHtml();
  ui->msgTxtEdit->clear();
  ui->msgTxtEdit->setFocus();
  return str;
}

void MainWindow::closeEvent(QCloseEvent *e) {
  emit this->closeWidget();
  sndMsg(UsrLeft);
  // 断开套接字
  udpSocket->close();
  udpSocket->destroyed();
  QWidget::closeEvent(e);
}
