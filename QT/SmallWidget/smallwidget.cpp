#include "smallwidget.h"

#include <QSlider>
#include <QSpinBox>

#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget* parent) : QWidget(parent), ui(new Ui::SmallWidget) {
    ui->setupUi(this);
    void (QSpinBox::*singal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, singal, ui->horizontalSlider, &QSlider::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

SmallWidget::~SmallWidget() { delete ui; }

void SmallWidget::setValue(int value) { ui->spinBox->setValue(value); }
int SmallWidget::getValue() { return ui->spinBox->value(); }
