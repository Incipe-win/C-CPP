#include "widget.h"
#include <QCloseEvent>
#include <QDebug>
#include <QImage>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QtGui>
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  // 不显示密码
  home = new Home();
  ui->passwd->setEchoMode(QLineEdit::Password);
  QString str = ":/bg3.jpg";
  setBackground(str);
  login();
}

// 背景图片
void Widget::setBackground(QString filename) {
  QPalette palette = this->palette();
  QImage background(filename);
  QImage fit = background.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
  palette.setBrush(QPalette::Window, QBrush(fit));
  this->setPalette(palette);
}

void Widget::login() {
  connect(ui->login, &QPushButton::clicked, [=]() {
    if (ui->passwd->text() == "incipe") {
      qDebug() << "login sucess!";
      home->setGeometry(this->geometry());
      home->show();
    } else {
      QMessageBox::critical(this, "passwd is wrong", "you can choose reset");
      // 重置密码
      connect(ui->reset, &QPushButton::clicked, [=]() {
        ui->passwd->setText("incipe");
        qDebug() << "reset sucess!";
      });
    }
  });
}

Widget::~Widget() { delete ui; }
