#ifndef UDP_H
#define UDP_H

#include <QUdpSocket>
#include <QWidget>

namespace Ui {
class Udp;
}

class Udp : public QWidget {
  Q_OBJECT

  public:
  explicit Udp(QWidget *parent = nullptr);
  ~Udp();

  private:
  Ui::Udp *ui;

  public:
  //套接字
  QUdpSocket *udp;
};

#endif  // UDP_H
