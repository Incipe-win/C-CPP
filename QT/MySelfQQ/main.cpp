#include "dialoglist.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  //  MainWindow w;
  //  w.show();
  DialogList list;
  list.show();
  return a.exec();
}
