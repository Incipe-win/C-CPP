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

void Music::setIcon(QString icon) { ui->play->setIcon(QIcon(icon)); }

void Music::init() {
  QStringList fileList = getFileNames(this->MusicPath);

  playlist = new QMediaPlaylist(this);
  player   = new QMediaPlayer(this);

  qDebug() << "All music file: \n" << fileList;
  for (int i = 0; i < (int)fileList.size(); ++i) {
    QString filename = fileList[i];
    addItem(filename);
    playlist->addMedia(QUrl::fromLocalFile(this->MusicPath + filename));
  }
  playlist->setCurrentIndex(order);
  player->setPlaylist(playlist);

  connect(ui->play, &QPushButton::clicked, [=]() {
    if (!this->isPlay) {
      isPlay = true;
      player->play();
      setIcon(":Play_on.png");
    } else {
      isPlay = false;
      player->pause();
      setIcon(":/play.png");
    }
  });

  connect(ui->next, &QPushButton::clicked, [=]() {
    if (!this->isPlay) {
      isPlay = true;
    }
    player->stop();
    setIcon(":/play.png");
    this->order += 1;
    this->order %= fileList.size();
    playlist->setCurrentIndex(this->order);
    player->play();
    setIcon(":/Play_on.png");
  });

  connect(ui->pre, &QPushButton::clicked, [=]() {
    if (!this->isPlay) {
      isPlay = true;
    }
    player->stop();
    setIcon(":/play.png");
    this->order -= 1;
    if (this->order < 0) {
      this->order += fileList.size();
    }
    playlist->setCurrentIndex(this->order);
    player->play();
    setIcon(":/Play_on.png");
  });

  connect(ui->back, &QPushButton::clicked, [=]() {
    isPlay = false;
    player->stop();
    setIcon(":/play.png");
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
