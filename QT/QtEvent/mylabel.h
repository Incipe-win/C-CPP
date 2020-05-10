#ifndef MYLABEL_H
#define MYLABEL_H

#include <QEvent>
#include <QLabel>
#include <QWidget>

class MyLabel : public QLabel {
  Q_OBJECT
  public:
  explicit MyLabel(QWidget* parent = nullptr);

  void enterEvent(QEvent*);

  void leaveEvent(QEvent*);

  void mousePressEvent(QMouseEvent* ev);
  void mouseReleaseEvent(QMouseEvent* ev);
  void mouseMoveEvent(QMouseEvent* ev);

  // 事件的分发 Event
  bool event(QEvent* e);
};

#endif  // MYLABEL_H
