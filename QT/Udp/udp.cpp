#include "udp.h"
#include <QUdpSocket>
#include "ui_udp.h"

Udp::Udp(QWidget *parent) : QWidget(parent), ui(new Ui::Udp) {
  ui->setupUi(this);
  //初始化属性
  ui->myPort->setText("9999");
  ui->toPort->setText("8888");
  ui->toIp->setText("127.0.0.1");

  //创建套接字
  udp = new QUdpSocket(this);

  //绑定自身端口号
  udp->bind(ui->myPort->text().toInt());

  //点击发送按钮，发送报文
  connect(ui->sendBtn, &QPushButton::clicked, [=]() {
    //书写报文 参数1  内容 2 对方Ip  3 对方端口
    udp->writeDatagram(ui->input->toPlainText().toUtf8(), QHostAddress(ui->toIp->text()), ui->toPort->text().toInt());

    ui->record->append("my Say :" + ui->input->toPlainText());

    //清空输入框
    ui->input->clear();
  });

  //接受数据
  connect(udp, &QUdpSocket::readyRead, [=]() {
    //获取到报文长度
    qint64 size = udp->pendingDatagramSize();

    QByteArray array = QByteArray(size, 0);

    //读取报文
    udp->readDatagram(array.data(), size);

    //将数据同步到聊天记录中
    ui->record->append(array);
  });
}

Udp::~Udp() { delete ui; }
