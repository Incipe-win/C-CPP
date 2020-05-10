#include "student.h"

#include <QDebug>

Student::Student(QObject* parent) : QObject(parent) {}

void Student::treat() { qDebug() << "Treat!"; }

void Student::treat(QString foodName) {
    //    qDebug() << "Treat teacher eat " << foodName;
    // QString 转 char *
    qDebug() << "Treat teacher eat" << foodName.toUtf8().data();
}
