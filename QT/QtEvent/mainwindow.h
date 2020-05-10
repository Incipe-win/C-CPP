#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QEvent>
#include <QMainWindow>
#include <QTimerEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

  public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  private:
  void timerEvent(QTimerEvent* e);
  Ui::MainWindow* ui;
  int id1;
  int id2;

  bool eventFilter(QObject* obj, QEvent* ev);
};
#endif  // MAINWINDOW_H
