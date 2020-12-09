#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out port\n");
    exit(-1);
  }
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  if (lfd < 0) {
    perror("socket error: ");
    exit(-1);
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[1]));
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  int ret = bind(lfd, (struct sockaddr *)&server, sizeof(server));
  if (ret < 0) {
    perror("bind error: ");
    exit(-1);
  }

  ret = listen(lfd, 1024);
  if (ret < 0) {
    perror("listen error: ");
    exit(-1);
  }

  struct sockaddr_in client;
  socklen_t len = sizeof(client);

  int maxfd = lfd;
  fd_set reads, temp;
  FD_ZERO(&reads);
  FD_SET(lfd, &reads);
  while (1) {
    temp = reads;
    ret = select(maxfd + 1, &temp, NULL, NULL, NULL);
    if (ret < 0) {
      perror("select error: ");
      exit(-1);
    }
    // 接受连接请求 accept不阻塞
    if (FD_ISSET(lfd, &temp)) {
      int cfd = accept(lfd, (struct sockaddr *)&client, &len);
      if (cfd < 0) {
        perror("accept error: ");
        exit(-1);
      }
      char ipbuf[64];
      printf("connect success, client ip %s, port %d\n",
             inet_ntop(AF_INET, &client.sin_addr.s_addr, ipbuf, sizeof(ipbuf)),
             ntohs(client.sin_port));
      FD_SET(cfd, &reads);
      maxfd = maxfd < cfd ? cfd : maxfd;
    }
    // 已经连接的客户端有数据到达
    for (int i = lfd + 1; i <= maxfd; ++i) {
      if (FD_ISSET(i, &temp)) {
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        int n = recv(i, buf, sizeof(buf), 0);
        if (n == -1) {
          perror("recv error: ");
          exit(-1);
        } else if (n == 0) {
          printf("client disconnect\n");
          close(i);
          FD_CLR(i, &reads);
        } else {
          printf("recv message: %s\n", buf);
          for (int j = 0; j < n; ++j) {
            buf[j] = toupper(buf[j]);
          }
          printf("send message: %s\n", buf);
          send(i, buf, sizeof(buf), 0);
        }
      }
    }
  }
  close(lfd);
  return 0;
}
