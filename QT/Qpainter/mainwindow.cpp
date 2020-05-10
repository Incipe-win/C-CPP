#include "mainwindow.h"
#include <QPushButton>
#include <QTimer>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  posX = 10;
  //  connect(ui->pushButton, &QPushButton::clicked, [=]() {
  //    posX += 10;
  //    // 手动调用绘图事件
  //    update();
  //  });
  QTimer *timer = new QTimer(this);
  timer->start(1000);
  connect(timer, &QTimer::timeout, [=]() {
    posX += 10;
    update();
  });
}

void MainWindow::paintEvent(QPaintEvent *) {
  QPainter painter(this);

  if (posX > this->width()) {
    posX = 10;
  }

  //  painter.drawPixmap(posX, 100, QPixmap("E:\\temp desktop\\png\\1-1.png"));
  painter.drawEllipse(QPoint(100, 100), 50, 50);
  //  // 设置抗锯齿, 效率低
  //  painter.setRenderHint(QPainter::HighQualityAntialiasing);
  //  painter.drawEllipse(QPoint(200, 100), 50, 50);
  //  painter.drawRect(QRect(20, 20, 50, 50));
  //  // 设置画家位置
  //  painter.translate(QPoint(100, 0));
  //  painter.save();
  //  painter.drawRect(QRect(20, 20, 50, 50));
  //  painter.translate(QPoint(100, 0));
  //  painter.restore();
  //  painter.drawRect(QRect(20, 20, 50, 50));
  //  //  QPen pen(QColor(255, 0, 0));
  //  QBrush brush(Qt::cyan);
  //  brush.setStyle(Qt::Dense4Pattern);
  //  painter.setBrush(brush);
  //  pen.setWidth(3);
  //  pen.setStyle(Qt::DashDotLine);
  //  painter.setPen(pen);
  //  painter.drawLine(QPoint(0, 0), QPoint(100, 100));
  //  painter.drawEllipse(QPoint(100, 100), 50, 50);
  //  painter.drawRect(QRect(10, 10, 50, 50));
  //  painter.drawText(QRect(10, 200, 150, 50), "Good Good study, day day up!");
}

MainWindow::~MainWindow() { delete ui; }
