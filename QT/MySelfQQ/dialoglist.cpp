#include "dialoglist.h"
#include <QDebug>
#include <QMessageBox>
#include <QToolButton>
#include "mainwindow.h"
#include "ui_dialoglist.h"

DialogList::DialogList(QWidget *parent) : QWidget(parent), ui(new Ui::DialogList) {
  ui->setupUi(this);
  // 设置标题
  setWindowTitle("MySelfQQ 2020");
  setWindowIcon(QPixmap(":/images/qq.png"));
  QList<QString> nameList;
  nameList << "水票奇缘"
           << "忆梦如澜"
           << "北京出版人"
           << "Cherry"
           << "淡然"
           << "娇娇girl"
           << "落水无痕"
           << "青墨暖暖"
           << "萌萌";

  QStringList iconNameList;  //图标资源列表
  iconNameList << "spqy"
               << "ymrl"
               << "qq"
               << "Cherry"
               << "dr"
               << "jj"
               << "lswh"
               << "qmnn"
               << "mm";
  // 保存九个按钮，方便以后操作
  QVector<QToolButton *> vToolBtn;

  for (int i = 0; i < 9; ++i) {
    // 设置头像
    QToolButton *btn = new QToolButton;
    btn->setText(nameList[i]);
    QString str = QString(":/images/%1.png").arg(iconNameList.at(i));
    btn->setIcon(QPixmap(str));
    btn->setIconSize(QPixmap(str).size());

    // 设置按钮风格 透明
    btn->setAutoRaise(true);
    // 设置文字和图片一起显示
    btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    // 加到垂直布局中
    ui->vLayout->addWidget(btn);
    vToolBtn.push_back(btn);
    isShow.push_back(false);
  }

  // 对九个按钮添加信号槽
  for (int i = 0; i < vToolBtn.size(); ++i) {
    connect(vToolBtn[i], &QToolButton::clicked, [=]() {
      if (isShow[i]) {
        QString str = QString("%1窗口已经被打开").arg(vToolBtn[i]->text());
        QMessageBox::warning(this, "警告", str);
        return;
      }

      isShow[i] = true;

      MainWindow *mainwindow = new MainWindow(0, vToolBtn[i]->text());
      mainwindow->setWindowTitle(vToolBtn[i]->text());
      mainwindow->setWindowIcon(vToolBtn[i]->icon());
      mainwindow->show();
      connect(mainwindow, &MainWindow::closeWidget, [=]() { isShow[i] = false; });
    });
  }
}

DialogList::~DialogList() { delete ui; }
