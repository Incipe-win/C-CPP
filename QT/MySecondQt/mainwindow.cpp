#include "mainwindow.h"

#include <QDebug>
#include <QPushButton>

#include "ui_mainwindow.h"

// 需求： 创建两个类，Teacher类 Student类

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    zt = new Teacher(this);
    st = new Student(this);
    //    connect(zt, &Teacher::hungry, st, &Student::treat);
    //    void (Teacher::*teacherSignal)(QString) = &Teacher::hungry;
    //    void (Student::*stSlot)(QString) = &Student::treat;
    //    connect(zt, teacherSignal, st, stSlot);
    //    classIsOver();
    // 点击按钮才下课
    QPushButton* btn = new QPushButton("class over", this);
    void (Teacher::*noTeacherSignal)(void) = &Teacher::hungry;
    connect(btn, &QPushButton::clicked, zt, noTeacherSignal);
    connect(btn, &QPushButton::clicked, this, &QWidget::close);
    void (Student::*noStSlot)(void) = &Student::treat;
    connect(zt, noTeacherSignal, st, noStSlot);
    //    disconnect(zt, noTeacherSignal, st, noStSlot);
    resize(600, 400);

    QPushButton* myBtn = new QPushButton(this);
    QPushButton* myBtn2 = new QPushButton(this);
    myBtn2->move(100, 100);
    int m = 10;
    connect(myBtn, &QPushButton::clicked, this, [m]() mutable {
        m = 100 + 10;
        qDebug() << m;
    });
    connect(myBtn2, &QPushButton::clicked, this, [=]() { qDebug() << m; });
    qDebug() << m;
}

void MainWindow::classIsOver() {
    // 触发老师饥饿信号
    // 老师饥饿信号是自定义信号，触发自定义信号关键字 emit
    emit zt->hungry();
    emit zt->hungry("beef");
}

MainWindow::~MainWindow() { delete ui; }
