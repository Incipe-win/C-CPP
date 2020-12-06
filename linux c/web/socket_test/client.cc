#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out port\n");
    return 0;
  }
  int cfd = socket(AF_INET, SOCK_STREAM, 0);
  if (cfd < 0) {
    perror("socker error");
    exit(-1);
  }
  // int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[1]));
  // int inet_pton(int af, const char *src, void *dst);
  inet_pton(AF_INET, "127.0.0.1", &server.sin_addr.s_addr);
  printf("[%p]\n", &server.sin_addr.s_addr);
  int ret = connect(cfd, (struct sockaddr *)&server, sizeof(server));
  if (ret < 0) {
    perror("connect error");
    exit(-1);
  }
  char buf[1024];
  while (1) {
    memset(buf, 0, sizeof(buf));
    printf("请输入要发送的数据: ");
    fgets(buf, sizeof(buf), stdin);
    write(cfd, buf, strlen(buf));
    /**
     * int n = read(STDIN_FILENO, buf, sizeof(buf));
     * write(cfd, buf, strlen(buf));
     * */
    memset(buf, 0, sizeof(buf));
    int n = read(cfd, buf, sizeof(buf));
    if (n < 0) {
      perror("read error");
      exit(-1);
    } else if (n == 0) {
      printf("服务器断开了连接\n");
      break;
    }
    printf("服务器发送过来的信息: %s\n", buf);
  }
  close(cfd);
  return 0;
}
