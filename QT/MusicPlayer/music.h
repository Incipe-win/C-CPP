#ifndef MUSIC_H
#define MUSIC_H

#include <QDebug>
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMovie>
#include <QProcess>
#include <QSoundEffect>
#include <QString>
#include <QStringList>
#include <QTableWidgetItem>
#include <QTextCodec>
#include <QWidget>

namespace Ui {
class Music;
}

class Music : public QWidget {
  Q_OBJECT

  public:
  explicit Music(QWidget *parent = nullptr);
  ~Music();

  private:
  Ui::Music *ui;
  bool isPlay = false;

  QMediaPlaylist *playlist;
  QMediaPlayer *player;

  int order = 0;

  QString MusicPath = "F:\\Repositories\\cpp\\QT\\MusicPlayer\\music\\";
  //  QString MusicPath = "F:\\Repositories\\cpp\\QT\\MusicPlayer\\";

  QStringList getFileNames(const QString &path);
  void setBackground(QString filename);
  void init();
  void addItem(QString name);
  //  // 设置透明
  void setLucency();
  void setIcon(QString icon);
};

#endif  // MUSIC_H
