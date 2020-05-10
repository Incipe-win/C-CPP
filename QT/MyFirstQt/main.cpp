#include <QApplication>

#include "mywindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    mywindow w;
    w.show();
    return a.exec();
}
