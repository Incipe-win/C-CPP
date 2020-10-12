#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  if (lfd == -1) {
    perror("socker error");
    exit(1);
  }
  struct sockaddr_in server;
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(8888);
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  int ret = bind(lfd, (struct sockaddr *)&server, sizeof(server));
  if (ret == -1) {
    perror("bind error");
    exit(1);
  }
  ret = listen(lfd, 20);
  if (ret == -1) {
    perror("listen error");
    exit(1);
  }
  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  int cfd = accept(lfd, (struct sockaddr *)&server, &len);
  if (cfd == -1) {
    perror("accept error");
    exit(1);
  }
  printf("accept successful !!!\n");
  char ipbuf[64] = {0};
  printf("client IP: %s, port: %d\n",
         inet_ntop(AF_INET, &client.sin_addr.s_addr, ipbuf, sizeof(ipbuf)),
         ntohs(client.sin_port));
  while (1) {
    char buf[1024] = {0};
    int len = read(cfd, buf, sizeof(buf));
    if (len == -1) {
      perror("read error");
      exit(1);
    } else if (len == 0) {
      printf("客户端断开连接\n");
      break;
    } else {
      printf("recv buf: %s\n", buf);
      for (int i = 0; i < len; ++i) {
        buf[i] = toupper(buf[i]);
      }
      printf("send buf: %s\n", buf);
      write(cfd, buf, len);
    }
  }
  close(lfd);
}
