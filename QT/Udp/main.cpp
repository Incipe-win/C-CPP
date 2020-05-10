#include "mainwindow.h"
#include "udp.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  Udp u;
  u.show();

  return a.exec();
}
