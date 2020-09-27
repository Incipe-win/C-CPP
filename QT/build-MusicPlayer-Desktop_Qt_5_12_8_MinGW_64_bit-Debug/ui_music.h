/********************************************************************************
** Form generated from reading UI file 'music.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSIC_H
#define UI_MUSIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Music
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *skin;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *back;
    QSpacerItem *horizontalSpacer_14;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pre;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *play;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *next;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_7;
    QSlider *slider;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_6;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Music)
    {
        if (Music->objectName().isEmpty())
            Music->setObjectName(QString::fromUtf8("Music"));
        Music->resize(800, 480);
        Music->setMinimumSize(QSize(800, 480));
        Music->setMaximumSize(QSize(800, 480));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/music.png"), QSize(), QIcon::Normal, QIcon::Off);
        Music->setWindowIcon(icon);
        widget = new QWidget(Music);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(8, 0, 791, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_13 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_13);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        skin = new QPushButton(widget);
        skin->setObjectName(QString::fromUtf8("skin"));
        skin->setMinimumSize(QSize(40, 40));
        skin->setMaximumSize(QSize(40, 40));
        skin->setStyleSheet(QString::fromUtf8("border-image: url(:/skin.png);"));

        horizontalLayout->addWidget(skin);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        back = new QPushButton(widget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setMinimumSize(QSize(40, 40));
        back->setMaximumSize(QSize(40, 40));
        back->setStyleSheet(QString::fromUtf8("border-image: url(:/fork.png);"));

        horizontalLayout->addWidget(back);

        horizontalSpacer_14 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_14);

        widget_2 = new QWidget(Music);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 411, 801, 61));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pre = new QPushButton(widget_2);
        pre->setObjectName(QString::fromUtf8("pre"));
        pre->setMinimumSize(QSize(50, 50));
        pre->setMaximumSize(QSize(50, 50));
        pre->setStyleSheet(QString::fromUtf8("border-image: url(:/pre.png);"));

        horizontalLayout_2->addWidget(pre);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        play = new QPushButton(widget_2);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMinimumSize(QSize(60, 60));
        play->setMaximumSize(QSize(60, 60));
        play->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon1);
        play->setIconSize(QSize(50, 50));

        horizontalLayout_2->addWidget(play);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        next = new QPushButton(widget_2);
        next->setObjectName(QString::fromUtf8("next"));
        next->setMinimumSize(QSize(50, 50));
        next->setMaximumSize(QSize(50, 50));
        next->setStyleSheet(QString::fromUtf8("border-image: url(:/next.png);"));

        horizontalLayout_2->addWidget(next);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setMaximumSize(QSize(50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/volume.png);"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        slider = new QSlider(widget_2);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(slider);

        horizontalSpacer_8 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        tableWidget = new QTableWidget(Music);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 50, 171, 361));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"background-color: rgba(255, 255, 255, 0);"));
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        retranslateUi(Music);

        QMetaObject::connectSlotsByName(Music);
    } // setupUi

    void retranslateUi(QWidget *Music)
    {
        Music->setWindowTitle(QApplication::translate("Music", "Music", nullptr));
        label->setText(QApplication::translate("Music", "incipe", nullptr));
        skin->setText(QString());
        back->setText(QString());
        pre->setText(QString());
        play->setText(QString());
        next->setText(QString());
        pushButton->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Music", "\346\255\214\346\233\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Music: public Ui_Music {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSIC_H
