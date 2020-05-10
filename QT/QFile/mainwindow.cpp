#include "mainwindow.h"
#include <QDataStream>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QPushButton>
#include <QTextCodec>
#include <QTextStream>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton, &QPushButton::clicked, [=]() {
    QString path = QFileDialog::getOpenFileName(this, "打开文件", "D:/Desktop");
    if (path.isEmpty()) {
      QMessageBox::warning(this, "警告", "打开失败");
    } else {
      ui->lineEdit->setText(path);
      // 读取文件
      QFile file(path);
      // 指定打开方式 只读
      //      file.open(QIODevice::ReadOnly);
      // utf-8
      //      QTextCodec *codec = QTextCodec::codecForName("gbk");
      file.open(QFileDevice::ReadOnly);
      QByteArray array;
      //      array = file.readAll();
      while (!file.atEnd()) {
        array += file.readLine();
      }
      ui->textEdit->setText(array);
      //      ui->textEdit->setText(codec->toUnicode(array));
      file.close();

      // 写文件
      //      file.open(QFileDevice::Append);
      //      file.write("hahahhahah");
      //      file.close();
      QFileInfo info(path);
      qDebug() << info.filePath() << " " << info.fileName() << " " << info.size() << " " << info.suffix();
      qDebug() << info.birthTime().toString("yyyy-MM-dd HH:mm::ss");
      qDebug() << info.lastModified().toString("yyyy/MM/dd HH:mm::ss");
    }
  });

  //文件流
  //文本流， 数据流
  //  QFile file("D:/Desktop/1.txt");
  //  file.open(QFileDevice::Append);
  //  QTextStream stream(&file);
  //  stream << QString("Hello World!") << 12345;
  //  file.close();
  //  file.open(QFileDevice::ReadOnly);
  //  QString str;
  //  //  stream >> str;
  //  //  //遇到空格
  //  str = stream.readAll();
  //  qDebug() << str;
  //  file.close();

  //二进制写
  QFile file("D:/Desktop/2.txt");
  file.open(QFileDevice::WriteOnly);
  QDataStream stream(&file);
  stream << QString("Hello World!") << 12345;
  file.close();

  file.open(QFileDevice::ReadOnly);
  QString str;
  int num;
  stream >> str >> num;
  qDebug() << str << num;
}

MainWindow::~MainWindow() { delete ui; }
