#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "student.h"
#include "teacher.h"

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
    Teacher* zt;
    Student* st;

    void classIsOver();

  private:
    Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
