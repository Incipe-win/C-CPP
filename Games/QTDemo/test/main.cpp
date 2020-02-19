#include <QApplication>
#include <iostream>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  int i = 0;
  std::cout << i << " " << ++i;
  w.show();
  return a.exec();
}
