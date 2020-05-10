/********************************************************************************
** Form generated from reading UI file 'mywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWINDOW_H
#define UI_MYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mywindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mywindow)
    {
        if (mywindow->objectName().isEmpty())
            mywindow->setObjectName(QString::fromUtf8("mywindow"));
        mywindow->resize(800, 600);
        centralwidget = new QWidget(mywindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mywindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mywindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        mywindow->setMenuBar(menubar);
        statusbar = new QStatusBar(mywindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mywindow->setStatusBar(statusbar);

        retranslateUi(mywindow);

        QMetaObject::connectSlotsByName(mywindow);
    } // setupUi

    void retranslateUi(QMainWindow *mywindow)
    {
        mywindow->setWindowTitle(QApplication::translate("mywindow", "mywindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mywindow: public Ui_mywindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWINDOW_H
