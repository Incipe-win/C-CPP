#ifndef HOME_H
#define HOME_H

#include <QString>
#include <QWidget>
#include "music.h"

namespace Ui {
class Home;
}

class Home : public QWidget {
  Q_OBJECT

  public:
  explicit Home(QWidget *parent = nullptr);
  ~Home();
  Music *music;

  private:
  Ui::Home *ui;
  void setBackground(QString filename);
  void connectMusic();
};

#endif  // HOME_H
