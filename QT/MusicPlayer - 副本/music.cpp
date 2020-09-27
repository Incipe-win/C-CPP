#include "music.h"
#include <QImage>
#include <QPalette>
#include "ui_music.h"

Music::Music(QWidget *parent) : QWidget(parent), ui(new Ui::Music) {
  ui->setupUi(this);

  QString str = ":/bg7.jpg";
  setBackground(str);

  connect(ui->back, &QPushButton::clicked, [=]() { this->close(); });

  init();
  setLucency();
}

void Music::setLucency() {
  QPalette pal = ui->tableWidget->palette();
  pal.setBrush(QPalette::Base, QBrush(QColor(255, 255, 255, 0)));
  ui->tableWidget->setPalette(pal);
  ui->tableWidget->setShowGrid(false);
  ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
  ui->tableWidget->verticalHeader()->setVisible(false);    //隐藏列表头
  ui->tableWidget->horizontalHeader()->setVisible(false);  //隐藏行表头
}

void Music::init() {
  QStringList fileList = getFileNames(this->MusicPath);
  qDebug() << "All music file: \n" << fileList;
  for (int i = 0; i < (int)fileList.size(); ++i) {
    QString filename = fileList[i];
    addItem(filename);
  }

  connect(ui->play, &QPushButton::clicked, [=]() {
    const char *command;
    QString lrcFileName = fileList[order].left(fileList[order].size() - 3) + "txt";
    qDebug() << lrcFileName;
    QFile file("/incipe/music/lrc/" + lrcFileName);
    //  QFile file("F:\\Repositories\\cpp\\QT\\MusicPlayer\\lrc\\" + lrcFileName);
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    file.open(QIODevice::ReadOnly);
    QByteArray array;

    array = file.readAll();
    ui->textEdit->clear();
    ui->textEdit->setText(codec->toUnicode(array));

    if (!this->isPlay) {
      qDebug() << "play music";

      if (this->isFirst) {
        isFirst   = false;
        QString c = "madplay " + fileList[order] + " &";

        command = c.toUtf8().constData();
      } else {
        command = "killall -SIGCONT madplay";
      }
      qDebug() << command;

      system(command);
      isPlay = true;
      ui->play->setIcon(QIcon(":/Play_on.png"));
    } else {
      isPlay = false;
      qDebug() << "music pause";
      command = "killall -SIGSTOP madplay";
      qDebug() << command;
      system(command);
      ui->play->setIcon(QIcon(":/play.png"));
    }
  });

  connect(ui->next, &QPushButton::clicked, [=]() {
    const char *command = "killall -SIGKILL madplay";
    system(command);
    if (order == (int)fileList.size() - 1) {
      order = -1;
    }
    QString c = "madplay " + fileList[++order] + " &";

    QString lrcFileName = fileList[order].left(fileList[order].size() - 3) + "txt";
    qDebug() << lrcFileName;
    QFile file("/incipe/music/lrc/" + lrcFileName);
    //  QFile file("F:\\Repositories\\cpp\\QT\\MusicPlayer\\lrc\\" + lrcFileName);
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    file.open(QIODevice::ReadOnly);
    QByteArray array;

    array = file.readAll();
    ui->textEdit->clear();
    ui->textEdit->setText(codec->toUnicode(array));

    command = c.toUtf8().constData();
    system(command);
    ui->play->setIcon(QIcon(":/Play_on.png"));
  });

  connect(ui->pre, &QPushButton::clicked, [=]() {
    const char *command = "killall -SIGKILL madplay";
    system(command);
    if (order == 0) {
      order = (int)fileList.size();
    }
    QString c = "madplay " + fileList[--order] + " &";

    QString lrcFileName = fileList[order].left(fileList[order].size() - 3) + "txt";
    qDebug() << lrcFileName;
    QFile file("/incipe/music/lrc/" + lrcFileName);
    //  QFile file("F:\\Repositories\\cpp\\QT\\MusicPlayer\\lrc\\" + lrcFileName);
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    file.open(QIODevice::ReadOnly);
    QByteArray array;

    array = file.readAll();
    ui->textEdit->clear();
    ui->textEdit->setText(codec->toUnicode(array));

    command = c.toUtf8().constData();
    system(command);
    ui->play->setIcon(QIcon(":/Play_on.png"));
  });

  connect(ui->back, &QPushButton::clicked, [=]() {
    if (this->isPlay) {
      const char *command = "killall -SIGKILL madplay";
      qDebug() << command;
      system(command);
    }
    this->isFirst = true;

    this->isPlay = false;
    ui->play->setIcon(QIcon(":/play.png"));
    QString filename = ":/bg7.jpg";
    setBackground(filename);

    //    const char *command = "killall -SIGKILL madplay";
    //    qDebug() << command;
    this->close();
  });

  connect(ui->skin, &QPushButton::clicked, [=]() {
    QString filename = ":/bg3.jpg";
    setBackground(filename);
  });
}

void Music::setBackground(QString filename) {
  QPalette palette = this->palette();
  QImage background(filename);
  QImage fit = background.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
  palette.setBrush(QPalette::Window, QBrush(fit));
  this->setPalette(palette);
}

QStringList Music::getFileNames(const QString &path) {
  QDir dir(path);
  QStringList nameFilters;
  nameFilters << "*.mp3";
  QStringList files = dir.entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);
  return files;
}

void Music::addItem(QString name) {
  int count = ui->tableWidget->rowCount();
  ui->tableWidget->setRowCount(count + 1);

  QTableWidgetItem *itemName = new QTableWidgetItem(name);
  ui->tableWidget->setItem(count, 0, itemName);
}

Music::~Music() { delete ui; }
