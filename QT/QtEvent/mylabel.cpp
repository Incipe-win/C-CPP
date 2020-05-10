#include "mylabel.h"

#include <QDebug>
#include <QMouseEvent>
#include <QPushButton>

MyLabel::MyLabel(QWidget* parent) : QLabel(parent) {
  // 设置鼠标追踪
  this->setMouseTracking(true);
}

void MyLabel::enterEvent(QEvent*) { qDebug() << "鼠标进入!"; }

void MyLabel::leaveEvent(QEvent*) { qDebug() << "鼠标离开!"; }

void MyLabel::mousePressEvent(QMouseEvent* ev) {
  if (ev->button() == Qt::LeftButton) {
    QString str = QString("鼠标按下了, x = %1, y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
  }
}
void MyLabel::mouseReleaseEvent(QMouseEvent* ev) {
  if (ev->button() == Qt::LeftButton) {
    QString str = QString("鼠标释放了, x = %1, y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
  }
}
void MyLabel::mouseMoveEvent(QMouseEvent* ev) {
  if (ev->buttons() & Qt::LeftButton) {
    QString str = QString("鼠标移动了, x = %1, y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
  }
  qDebug() << "鼠标移动了!";
  //    if (ev->button() == Qt::LeftButton) {
  //        QString str = QString("鼠标移动了, x = %1, y = %2").arg(ev->x()).arg(ev->y());
  //        qDebug() << str;
  //    }
}

bool MyLabel::event(QEvent* e) {
  if (e->type() == QEvent::MouseButtonPress) {
    QMouseEvent* ev = static_cast<QMouseEvent*>(e);
    QString str     = QString("Event鼠标按下了, x = %1, y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
    return true;
  }
  return QLabel::event(e);
}
