#include "mainwindow.h"

#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QPushButton>
#include <QTimer>
#include <QTimerEvent>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // 每1000毫秒调用一次timeEvent事件
  id1 = startTimer(1000);
  id2 = startTimer(2000);

  // 定时器第二种方式
  QTimer *timer = new QTimer(this);
  //启动定时器
  timer->start(500);
  // 每隔0.5秒发送一个信号
  connect(timer, &QTimer::timeout, [=]() {
    static int num = 0;
    ui->label_4->setText(QString::number(num++));
  });

  connect(ui->pushButton, &QPushButton::clicked, [=]() { timer->stop(); });
  //  connect(ui->pushButton, &QPushButton::clicked, timer, &QTimer::stop);

  // 给控件安装事件过滤器
  ui->label->installEventFilter(this);
  // 重写
}
bool MainWindow::eventFilter(QObject *obj, QEvent *e) {
  if (obj == ui->label) {
    if (e->type() == QEvent::MouseButtonPress) {
      QMouseEvent *ev = static_cast<QMouseEvent *>(e);
      QString str     = QString("EventFilter鼠标按下了, x = %1, y = %2").arg(ev->x()).arg(ev->y());
      qDebug() << str;
      return true;
    }
  }
  return QWidget::eventFilter(obj, e);
}

void MainWindow::timerEvent(QTimerEvent *e) {
  if (e->timerId() == id1) {
    static int num = 0;
    ui->label_2->setText(QString::number(num++));
  }
  if (e->timerId() == id2) {
    static int num2 = 0;
    ui->label_3->setText(QString::number(num2++));
  }
  qDebug("timer event, id %d", e->timerId());
};

MainWindow::~MainWindow() { delete ui; }
