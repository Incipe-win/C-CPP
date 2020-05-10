#include "mainwindow.h"

#include <QDebug>
#include <QPushButton>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->btnSet, &QPushButton::clicked, [=]() { ui->widget->setValue(50); });
    connect(ui->btnGet, &QPushButton::clicked, [=]() { qDebug() << "当前值为: " << ui->widget->getValue(); });
}

MainWindow::~MainWindow() { delete ui; }
