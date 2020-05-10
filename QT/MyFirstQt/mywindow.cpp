#include "mywindow.h"

#include <QPushButton>

#include "ui_mywindow.h"

mywindow::mywindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::mywindow) {
    ui->setupUi(this);
    QPushButton* btn = new QPushButton;
    //    btn->show(); // 顶层方式弹出
    // 弹出按钮
    btn->setParent(this);
    // 设置按钮文本
    btn->setText("Hello World!");
    // 设置按钮大小
    btn->resize(150, 50);

    // 第二种方法创建按钮
    QPushButton* btn1 = new QPushButton("第二个按钮！", this);
    // 设置宽口大小
    this->resize(600, 400);
    // 移动按钮
    btn1->move(100, 100);

    //设置窗口标题
    setWindowTitle("incipe");
    // 固定窗口大小
    setFixedSize(600, 400);
    // 点击按钮关闭窗口
    connect(btn1, &QPushButton::clicked, this, &QWidget::close);
}

mywindow::~mywindow() { delete ui; }
