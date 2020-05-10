#include "mainwindow.h"

#include <QDockWidget>
#include <QLabel>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    resize(600, 400);
    // 菜单栏
    QMenuBar* bar = menuBar();
    this->setMenuBar(bar);
    QMenu* file = bar->addMenu("File");
    QMenu* edit = bar->addMenu("Edit");

    QAction* newAction1 = file->addAction("Create");
    file->addSeparator();
    QAction* newAction2 = file->addAction("Open");
    edit->addAction("Undo");

    // 工具栏
    QToolBar* toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolBar->setFloatable(false);
    toolBar->setMovable(false);
    toolBar->addAction(newAction1);
    toolBar->addSeparator();
    toolBar->addAction(newAction2);

    // 状态栏
    QStatusBar* stBar = new QStatusBar(this);
    setStatusBar(stBar);
    QLabel* lable = new QLabel("tips", this);
    stBar->addWidget(lable);
    QLabel* label1 = new QLabel("close", this);
    stBar->addPermanentWidget(label1);

    // 浮动窗口
    QDockWidget* dock = new QDockWidget;
    addDockWidget(Qt::BottomDockWidgetArea, dock);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    // 核心部件
    QTextEdit* textEdit = new QTextEdit;
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow() { delete ui; }
