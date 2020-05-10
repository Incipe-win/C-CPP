#include "mainwindow.h"

#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->actionnew, &QAction::triggered, this, [=]() {
        // 对话框两种 模态对话框（不可以对其他窗口操作）， 非模态对话框（可以）

        //        // 模态
        //        QDialog dlg(this);
        //        dlg.resize(600, 400);
        //        dlg.exec();
        // 非模态
        //        QDialog dlg2(this); 栈上
        //        QDialog* dlg2 = new QDialog(this);
        //        dlg2->resize(600, 400);
        //        dlg2->show();
        //        dlg2->setAttribute(Qt::WA_DeleteOnClose);

        //        qDebug() << "弹出对话框!";

        // 使用标准对话框
        //        QMessageBox::critical(this, "Fault!", "critical");
        //        QMessageBox::information(this, "information", "info");
        // 参数1 父亲， 参数2 标题， 参数3 问题， 参数4 按键类型， 参数5 关联回车链接
        //        if (QMessageBox::question(this, "question", "Are you like he/she?", QMessageBox::Yes |
        //        QMessageBox::No,
        //                                  QMessageBox::No)) {
        //            qDebug() << "congratulations!";
        //        } else {
        //            qDebug() << "word hard!";
        //        }
        //        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
        //        qDebug() << color.red() << color.green() << color.blue();
        QFileDialog::getOpenFileName(this, "打开文件", "D:/Desktop", "(*.txt *.png)");
    });
}

MainWindow::~MainWindow() { delete ui; }
