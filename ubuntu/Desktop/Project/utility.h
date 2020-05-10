#ifndef CHAT_UTILITY_H
#define CHAT_UTILITY_H

#include <iostream>
#include <list>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//clients_list save all the clients's socket
list<int> clients_list;

/***** macro defintion *****/
//server ip
#define SERVER_IP "127.0.0.1"

//server port
#define SERVER_PORT 8888

//epoll size
#define EPOLL_SIZE 5000

//message buffer size
#define BUF_SIZE 0xFFFF

#define SERVER_WELCOME "Welcome you join to the chat room! Your chat ID is: Client #%d"

#define SERVER_MESSAGE "ClientID %d say >> %s"

//exit
#define EXIT "EXIT"

#define CAUTION "There is only ont int the char root!"

/****** some function *****/
/**
 *设置非阻塞
 */
int setnonblockint(int sockfd) {
    fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
    return 0;
}

/**
 * 将文件描述符 fd 添加到 epollfd 标示的内核事件表中,
 * 并注册 EPOLLIN 和 EPOOLET 事件,
 * EPOLLIN 是数据可读事件；EPOOLET 表明是 ET 工作方式。
 * 最后将文件描述符设置非阻塞方式
 * @param epollfd:epoll句柄
 * @param fd:文件描述符
 * @param enable_et:enable_et = true,
 * 是否采用epoll的ET(边缘触发)工作方式；否则采用LT(水平触发)工作方式
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
int sendBroadcastmessage(int clientfd) {
    char buf[BUF_SIZE];
    char message[BUF_SIZE];
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
        for (it = clients_list.begin(); it != clients_list.end(); ++it) {
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

#endif //CHAT_UTILITY_H
