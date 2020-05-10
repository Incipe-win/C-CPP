/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *msgBrowser;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *frontCbx;
    QComboBox *sizeCbx;
    QToolButton *blodTBtn;
    QToolButton *italicTBtn;
    QToolButton *underlineTBtn;
    QToolButton *colorTBtn;
    QToolButton *saveTBtn;
    QToolButton *clearTBtn;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *msgTxtEdit;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *usrTblWidget;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sendBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *usrNumLbl;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(widget_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(frame_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        msgBrowser = new QTextBrowser(widget);
        msgBrowser->setObjectName(QString::fromUtf8("msgBrowser"));

        horizontalLayout_2->addWidget(msgBrowser);


        verticalLayout->addWidget(widget);

        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frontCbx = new QFontComboBox(frame_2);
        frontCbx->setObjectName(QString::fromUtf8("frontCbx"));

        horizontalLayout->addWidget(frontCbx);

        sizeCbx = new QComboBox(frame_2);
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->addItem(QString());
        sizeCbx->setObjectName(QString::fromUtf8("sizeCbx"));

        horizontalLayout->addWidget(sizeCbx);

        blodTBtn = new QToolButton(frame_2);
        blodTBtn->setObjectName(QString::fromUtf8("blodTBtn"));
        blodTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        blodTBtn->setIcon(icon);
        blodTBtn->setIconSize(QSize(26, 26));
        blodTBtn->setCheckable(true);

        horizontalLayout->addWidget(blodTBtn);

        italicTBtn = new QToolButton(frame_2);
        italicTBtn->setObjectName(QString::fromUtf8("italicTBtn"));
        italicTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicTBtn->setIcon(icon1);
        italicTBtn->setIconSize(QSize(26, 26));
        italicTBtn->setCheckable(true);

        horizontalLayout->addWidget(italicTBtn);

        underlineTBtn = new QToolButton(frame_2);
        underlineTBtn->setObjectName(QString::fromUtf8("underlineTBtn"));
        underlineTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineTBtn->setIcon(icon2);
        underlineTBtn->setIconSize(QSize(26, 26));
        underlineTBtn->setCheckable(true);

        horizontalLayout->addWidget(underlineTBtn);

        colorTBtn = new QToolButton(frame_2);
        colorTBtn->setObjectName(QString::fromUtf8("colorTBtn"));
        colorTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/xx.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorTBtn->setIcon(icon3);
        colorTBtn->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(colorTBtn);

        saveTBtn = new QToolButton(frame_2);
        saveTBtn->setObjectName(QString::fromUtf8("saveTBtn"));
        saveTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveTBtn->setIcon(icon4);
        saveTBtn->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(saveTBtn);

        clearTBtn = new QToolButton(frame_2);
        clearTBtn->setObjectName(QString::fromUtf8("clearTBtn"));
        clearTBtn->setMinimumSize(QSize(33, 33));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearTBtn->setIcon(icon5);
        clearTBtn->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(clearTBtn);


        verticalLayout->addWidget(frame_2);

        widget_2 = new QWidget(frame_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 100));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        msgTxtEdit = new QTextEdit(widget_2);
        msgTxtEdit->setObjectName(QString::fromUtf8("msgTxtEdit"));
        msgTxtEdit->setMaximumSize(QSize(16777215, 100));

        verticalLayout_2->addWidget(msgTxtEdit);


        verticalLayout->addWidget(widget_2);


        horizontalLayout_5->addWidget(frame_3);

        frame_4 = new QFrame(widget_4);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMaximumSize(QSize(180, 16777215));
        frame_4->setFrameShape(QFrame::Box);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        usrTblWidget = new QTableWidget(frame_4);
        if (usrTblWidget->columnCount() < 1)
            usrTblWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usrTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        usrTblWidget->setObjectName(QString::fromUtf8("usrTblWidget"));
        usrTblWidget->setSelectionMode(QAbstractItemView::SingleSelection);

        horizontalLayout_3->addWidget(usrTblWidget);


        horizontalLayout_5->addWidget(frame_4);


        verticalLayout_4->addWidget(widget_4);

        frame_5 = new QFrame(widget_6);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::Box);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        sendBtn = new QPushButton(frame_5);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout_4->addWidget(sendBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        usrNumLbl = new QLabel(frame_5);
        usrNumLbl->setObjectName(QString::fromUtf8("usrNumLbl"));

        horizontalLayout_4->addWidget(usrNumLbl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        exitBtn = new QPushButton(frame_5);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        horizontalLayout_4->addWidget(exitBtn);


        verticalLayout_4->addWidget(frame_5);


        verticalLayout_5->addWidget(widget_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        sizeCbx->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        sizeCbx->setItemText(0, QApplication::translate("MainWindow", "8", nullptr));
        sizeCbx->setItemText(1, QApplication::translate("MainWindow", "9", nullptr));
        sizeCbx->setItemText(2, QApplication::translate("MainWindow", "10", nullptr));
        sizeCbx->setItemText(3, QApplication::translate("MainWindow", "11", nullptr));
        sizeCbx->setItemText(4, QApplication::translate("MainWindow", "12", nullptr));
        sizeCbx->setItemText(5, QApplication::translate("MainWindow", "13", nullptr));
        sizeCbx->setItemText(6, QApplication::translate("MainWindow", "14", nullptr));
        sizeCbx->setItemText(7, QApplication::translate("MainWindow", "15", nullptr));
        sizeCbx->setItemText(8, QApplication::translate("MainWindow", "16", nullptr));
        sizeCbx->setItemText(9, QApplication::translate("MainWindow", "17", nullptr));
        sizeCbx->setItemText(10, QApplication::translate("MainWindow", "18", nullptr));
        sizeCbx->setItemText(11, QApplication::translate("MainWindow", "19", nullptr));
        sizeCbx->setItemText(12, QApplication::translate("MainWindow", "20", nullptr));
        sizeCbx->setItemText(13, QApplication::translate("MainWindow", "21", nullptr));
        sizeCbx->setItemText(14, QApplication::translate("MainWindow", "22", nullptr));

#ifndef QT_NO_TOOLTIP
        blodTBtn->setToolTip(QApplication::translate("MainWindow", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        blodTBtn->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        italicTBtn->setToolTip(QApplication::translate("MainWindow", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        italicTBtn->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        underlineTBtn->setToolTip(QApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        underlineTBtn->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        colorTBtn->setToolTip(QApplication::translate("MainWindow", "\344\277\256\346\224\271\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        colorTBtn->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        saveTBtn->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_NO_TOOLTIP
        saveTBtn->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        clearTBtn->setToolTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
#endif // QT_NO_TOOLTIP
        clearTBtn->setText(QApplication::translate("MainWindow", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = usrTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        sendBtn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
#ifndef QT_NO_SHORTCUT
        sendBtn->setShortcut(QApplication::translate("MainWindow", "Ctrl+Return", nullptr));
#endif // QT_NO_SHORTCUT
        usrNumLbl->setText(QApplication::translate("MainWindow", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\2320\344\272\272", nullptr));
        exitBtn->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_SHORTCUT
        exitBtn->setShortcut(QApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
