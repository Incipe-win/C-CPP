#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mywindow; }
QT_END_NAMESPACE

class mywindow : public QMainWindow
{
  Q_OBJECT

public:
  mywindow(QWidget *parent = nullptr);
  ~mywindow();

private:
  Ui::mywindow *ui;
};
#endif // MYWINDOW_H
