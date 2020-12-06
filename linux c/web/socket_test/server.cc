#include <arpa/inet.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 创建socket
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  if (lfd < 0) {
    perror("socker error");
    exit(-1);
  }

  // 绑定
  struct sockaddr_in server;
  // bzero(&server, sizeof(server));
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(8888);
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  int ret = bind(lfd, (sockaddr *)&server, sizeof(server));
  if (ret < 0) {
    perror("bind error");
    exit(-1);
  }

  // 监听
  listen(lfd, 128);

  // 获取client客户端的ip和端口
  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  int cfd = accept(lfd, (struct sockaddr *)&client, &len);
  printf("lfd is %d, cfd is %d\n", lfd, cfd);
  char ipbuf[64];
  memset(ipbuf, 0, sizeof(ipbuf));
  printf("client ip is: %s, port is: %d\n",
         inet_ntop(AF_INET, &client.sin_addr.s_addr, ipbuf, sizeof(ipbuf)),
         ntohs(client.sin_port));
  char buf[1024];
  while (1) {
    memset(buf, 0, sizeof(buf));
    int n = 0;
    n = read(cfd, buf, sizeof(buf));
    if (n == -1) {
      perror("read error");
      break;
    } else if (n == 0) {
      printf("客户端断开连接\n");
      break;
    }
    printf("客户端发送过来的信息: %s\n", buf);
    for (int i = 0; i < n; ++i) {
      buf[i] = toupper(buf[i]);
    }
    printf("发送给服务器的信息: %s\n", buf);
    write(cfd, buf, n);
  }
  close(cfd);
  close(lfd);
  return 0;
}
