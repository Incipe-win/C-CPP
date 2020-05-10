/********************************************************************************
** Form generated from reading UI file 'smallwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLWIDGET_H
#define UI_SMALLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmallWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *SmallWidget)
    {
        if (SmallWidget->objectName().isEmpty())
            SmallWidget->setObjectName(QString::fromUtf8("SmallWidget"));
        SmallWidget->resize(482, 69);
        horizontalLayout = new QHBoxLayout(SmallWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spinBox = new QSpinBox(SmallWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(SmallWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        retranslateUi(SmallWidget);

        QMetaObject::connectSlotsByName(SmallWidget);
    } // setupUi

    void retranslateUi(QWidget *SmallWidget)
    {
        SmallWidget->setWindowTitle(QApplication::translate("SmallWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmallWidget: public Ui_SmallWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWIDGET_H
