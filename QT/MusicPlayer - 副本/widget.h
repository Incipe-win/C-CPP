#ifndef WIDGET_H
#define WIDGET_H

#include <QString>
#include <QWidget>
#include "home.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

  public:
  Home *home;
  Widget(QWidget *parent = nullptr);
  ~Widget();

  private:
  Ui::Widget *ui;
  void setBackground(QString filename);
  void login();
};
#endif  // WIDGET_H
