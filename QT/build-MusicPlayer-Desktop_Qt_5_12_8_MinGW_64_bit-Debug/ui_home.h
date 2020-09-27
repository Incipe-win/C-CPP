/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Home
{
public:
    QPushButton *back;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *vedio;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *music;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ad;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *photo;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *goBang;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *game;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *Home)
    {
        if (Home->objectName().isEmpty())
            Home->setObjectName(QString::fromUtf8("Home"));
        Home->resize(800, 480);
        Home->setMinimumSize(QSize(800, 480));
        Home->setMaximumSize(QSize(800, 480));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        Home->setWindowIcon(icon);
        back = new QPushButton(Home);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(740, 420, 50, 50));
        back->setMinimumSize(QSize(50, 50));
        back->setMaximumSize(QSize(50, 50));
        back->setStyleSheet(QString::fromUtf8("border-image: url(:/back.png);"));
        widget_4 = new QWidget(Home);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(10, 10, 750, 400));
        widget_4->setMinimumSize(QSize(750, 400));
        widget_4->setMaximumSize(QSize(750, 400));
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        vedio = new QPushButton(widget);
        vedio->setObjectName(QString::fromUtf8("vedio"));
        vedio->setMinimumSize(QSize(100, 100));
        vedio->setMaximumSize(QSize(100, 100));
        vedio->setStyleSheet(QString::fromUtf8("border-image: url(:/vedio-validate.png);"));

        horizontalLayout_2->addWidget(vedio);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        music = new QPushButton(widget);
        music->setObjectName(QString::fromUtf8("music"));
        music->setMinimumSize(QSize(100, 100));
        music->setMaximumSize(QSize(100, 100));
        music->setStyleSheet(QString::fromUtf8("border-image: url(:/music.png);"));

        horizontalLayout_2->addWidget(music);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        ad = new QPushButton(widget_2);
        ad->setObjectName(QString::fromUtf8("ad"));
        ad->setMinimumSize(QSize(100, 100));
        ad->setMaximumSize(QSize(100, 100));
        ad->setStyleSheet(QString::fromUtf8("border-image: url(:/Advertisement.png);"));

        horizontalLayout->addWidget(ad);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        photo = new QPushButton(widget_2);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setMinimumSize(QSize(100, 100));
        photo->setMaximumSize(QSize(100, 100));
        photo->setStyleSheet(QString::fromUtf8("border-image: url(:/photo.png);"));

        horizontalLayout->addWidget(photo);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        goBang = new QPushButton(widget_3);
        goBang->setObjectName(QString::fromUtf8("goBang"));
        goBang->setMinimumSize(QSize(100, 100));
        goBang->setMaximumSize(QSize(100, 100));
        goBang->setStyleSheet(QString::fromUtf8("border-image: url(:/Gobang.png);"));

        horizontalLayout_3->addWidget(goBang);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        game = new QPushButton(widget_3);
        game->setObjectName(QString::fromUtf8("game"));
        game->setMinimumSize(QSize(100, 100));
        game->setMaximumSize(QSize(100, 100));
        game->setStyleSheet(QString::fromUtf8("border-image: url(:/2048_web_logo.png);"));

        horizontalLayout_3->addWidget(game);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        gridLayout->addWidget(widget_3, 2, 0, 1, 1);


        retranslateUi(Home);

        QMetaObject::connectSlotsByName(Home);
    } // setupUi

    void retranslateUi(QWidget *Home)
    {
        Home->setWindowTitle(QApplication::translate("Home", "Home", nullptr));
        back->setText(QString());
        vedio->setText(QString());
        music->setText(QString());
        ad->setText(QString());
        photo->setText(QString());
        goBang->setText(QString());
        game->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Home: public Ui_Home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
