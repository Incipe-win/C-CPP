#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
  enum MsgType { Msg, UsrEnter, UsrLeft };

  public:
  MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {}
  MainWindow(QWidget *parent, QString name);
  ~MainWindow();
  // 关闭事件
  void closeEvent(QCloseEvent *e);

  private:
  Ui::MainWindow *ui;
  signals:
  // 关闭窗口发送关闭信息
  void closeWidget();

  public:
  void sndMsg(MsgType type);                    //广播UDP消息
  void usrEnter(QString username);              //处理新用户加入
  void usrLeft(QString usrname, QString time);  //处理用户离开
  QString getUsr();                             //获取用户名
  QString getMsg();                             //获取聊天信息
  private:
  QUdpSocket *udpSocket;  // udp套接字
  qint16 port;            //端口
  QString uName;          //用户名

  void ReceiveMessage();  //接受UDP消息
};
#endif  // MAINWINDOW_H
