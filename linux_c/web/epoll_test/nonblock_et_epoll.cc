#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out port\n");
    exit(-1);
  }
  int lfd;
  if ((lfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket error: ");
    exit(-1);
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[1]));
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(lfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind error: ");
    exit(-1);
  }

  if (listen(lfd, 1024) < 0) {
    perror("listen error: ");
    exit(-1);
  }

  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  char ipbuf[64];

  // 创建epoll树根节点
  int epfd = epoll_create(1024);
  // 初始化epoll树
  struct epoll_event ev;
  ev.events = EPOLLIN | EPOLLET;
  ev.data.fd = lfd;
  epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
  struct epoll_event all[1024];
  while (1) {
    // 使用epoll通知内核fd 文件io检测
    int ret = epoll_wait(epfd, all, sizeof(all) / sizeof(all[0]), -1);
    // 遍历all数组中的前ret个元素
    for (int i = 0; i < ret; ++i) {
      int fd = all[i].data.fd;
      if (fd == lfd) {
        int cfd;
        if ((cfd = accept(lfd, (struct sockaddr *)&client, &len)) < 0) {
          perror("accept error: ");
          exit(-1);
        }
        printf(
            "connect sucess, client ip is %s, port is %d\n",
            inet_ntop(AF_INET, &client.sin_addr.s_addr, ipbuf, sizeof(ipbuf)),
            client.sin_port);
        // 设置cfd非阻塞
        int flag = fcntl(cfd, F_GETFL);
        flag |= O_NONBLOCK;
        fcntl(cfd, F_SETFL, flag);
        // 将得到的cfd挂到树上
        struct epoll_event temp;
        // EPOLLIN 水平触发 默认
        // 设置边缘触发
        temp.events = EPOLLIN | EPOLLET;
        temp.data.fd = cfd;
        epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &temp);
      } else {
        if (!(all[i].events & EPOLLIN)) {
          continue;
        }
        char buf[5];
        memset(buf, 0, sizeof(buf));
        int size;
        printf("recv message: \n");
        while ((size = recv(fd, buf, sizeof(buf), 0)) > 0) {
          write(STDOUT_FILENO, buf, size);
        }
        if (size == 0) {
          printf("client disconnect!\n");
          // 将fd从树上删除
          if (epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL) < 0) {
            perror("epoll_ctl -del error: ");
            exit(-1);
          }
          close(fd);
          break;
        } else if (size == -1) {
          if (errno == EAGAIN) {
            printf("\nmessage is read over!\n");
          } else {
            perror("recv error: ");
            exit(-1);
          }
        }

#if 0
        if ((size = recv(fd, buf, sizeof(buf), 0)) < 0) {
          perror("recv error: ");
        } else if (size == 0) {
          printf("client disconnect!\n");
          // 将fd从树上删除
          if (epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL) < 0) {
            perror("epoll_ctl -del error: ");
            exit(-1);
          }
          close(fd);
          break;
        } else {
          printf("recv message: %s\n", buf);
          for (int j = 0; j < size; ++j) {
            buf[j] = toupper(buf[j]);
          }
          printf("send message: %s\n", buf);
          send(fd, buf, size, 0);
        }
#endif
      }
    }
  }
  close(lfd);
  return 0;
}
