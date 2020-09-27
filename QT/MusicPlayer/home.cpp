#include "home.h"
#include <QDebug>
#include <QImage>
#include <QPalette>
#include "ui_home.h"

Home::Home(QWidget *parent) : QWidget(parent), ui(new Ui::Home) {
  ui->setupUi(this);
  music = new Music();

  QString str = ":/bg2.jpg";
  setBackground(str);
  connectMusic();
}

void Home::setBackground(QString filename) {
  QPalette palette = this->palette();
  QImage background(filename);
  QImage fit = background.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
  palette.setBrush(QPalette::Window, QBrush(fit));
  this->setPalette(palette);
}

void Home::connectMusic() {
  connect(ui->music, &QPushButton::clicked, [=]() {
    qDebug() << "Welecome come to music world!";
    music->setGeometry(this->geometry());
    music->show();
  });
  connect(ui->back, &QPushButton::clicked, [=]() { this->close(); });
}

Home::~Home() { delete ui; }
