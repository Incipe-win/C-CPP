#ifndef UNTILITY_H_
#define UNTILITY_H_

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <list>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/scoket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

//客户端列表保存所有客户端套接字
list<int> clients_list;

/*****宏定义*****/
// server ip
#define SERVER_IP "127.0.0.1"

// server port
#define SERVER_PORT "8888"

// epoll size
#define EPOLL_SIZE 5000

// message buffer size
#define BUF_SIZE 0xFFFF

#define SERVER_WELCOME                                                         \
  "Welcome you join to the room! You chat ID is: Client #%d"

#define SERVER_MESSAGE "ClientID %d say >> %s"

// exit
#define EXIT "EXIT"

#define CAUTION "There is only ont int the char root!"

/****** some function ********/
/*
 * 设置非阻塞
 */
int setnonblockint(int sockfd) {
  fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
  return 0;
}

/**
 * 将文件描述符fd添加到epollfd标识的内核事件表中，
 * 并注册EPOLLIN 和 EPOLLET 事件，
 * EPOLLIN 是数据可读事件；EPOPLET 表明是ET 工作方式。
 * 最后将文件描述符设置非阻塞方式
 * @param epollfd:epoll句柄
 * @param fd:文件描述符
 * @param enable_et:enable_et = true,
 * 是否采用epoll的ET（边缘触发）工作方式；否则采用LT（水平触发）工作方式
 */
void addfd(int epollfd, int fd, bool enable_et) {
  struct epoll_event ev;
  ev.data.fd = fd;
  ev.events = EPOLLIN;
  if (enable_et) {
    ev.events = EPOLLIN | EPOLLET;
  }
  epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
  setnonblockint(fd);
  printf("fd added to epoll!\n\n");
}

//发送广播
int sendBroadcastmessage(int clintfd) {
  char buf[BUF_SIZE];
  char messagae[BUF_SIZE];
  bzero(buf, BUF_SIZE);
  bzero(buf, BUF_SIZE);

  printf("read from client(clientID = %d)\n", clientfd);
  int len = recv(clientfd, buf, BUF_SIZE, 0);
  if (0 == len) {
    close(clientfd);
    clients_list.remove(clientfd);
    printf("ClientID = %d closed.\n now there are %d client in the char room\n",
           clientfd, (int)clients_list.size());
  } else {
    if (1 == clients_list.size()) {
      send(clientfd, CAUTION, strlen(CAUTION), 0);
      return 0;
    }
    sprintf(message, SERVER_MESSAGE, clientfd, buf);
    list<int>::iterator it;
    for (it = client_list.begin(); it != client_list.end(); ++it) {
      if (*it != clientfd) {
        if (send(*it, message, BUF_SIZE, 0) < 0) {
          perror("error");
          exit(-1);
        }
      }
    }
  }
  return len;
}

#endif // UNTILITY_H_