#include "mainwindow.h"
#include <QPainter>
#include <QPicture>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QPicture pic;
  QPainter painter(this);
  painter.begin(&pic);
  painter.setPen(QPen(QColor(255, 192, 203)));
  painter.drawEllipse(QPoint(150, 150), 100, 100);
  painter.end();
  pic.save("D:/Desktop/pic.zt");
}

void MainWindow::paintEvent(QPaintEvent *) {
  //  // QPixmap 做绘图
  //  QPixmap pix(300, 300);
  //  pix.fill(Qt::white);
  //  QPainter painter(&pix);
  //  painter.setPen(QPen(Qt::green));
  //  painter.drawEllipse(QPoint(150, 150), 100, 100);
  //  pix.save("D:/Desktop/pix.png");

  //  QImage img(300, 300, QImage::Format_RGB32);
  //  img.fill(Qt::white);
  //  QPainter painter(&img);
  //  //  QPainter painter(this);
  //  QPen pen(QColor(255, 192, 203));
  //  painter.setPen(pen);
  //  painter.setPen(QPen(QColor(255, 192, 203)));
  //  painter.drawEllipse(QPoint(150, 150), 100, 100);
  //  img.save("D:/Desktop/img.png");
  //  QImage img;
  //  img.load("E:\\temp desktop\\png\\1-1.png");
  //  for (int i = 0; i < 100; ++i) {
  //    for (int j = 0; j < 100; ++j) {
  //      QRgb value = qRgb(255, 0, 0);
  //      img.setPixel(i, j, value);
  //    }
  //  }
  //  QPainter painter(this);
  //  painter.drawImage(QPoint(0, 0), img);
  //  img.save("D:/Desktop/1.png");
  QPicture pic;
  pic.load("D:/Desktop/pic.zt");
  QPainter painter(this);
  painter.drawPicture(0, 0, pic);
}

MainWindow::~MainWindow() { delete ui; }
