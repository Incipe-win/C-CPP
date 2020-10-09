#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("eg: ./a.out port\n");
    exit(1);
  }
  int port = atoi(argv[1]);
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in serv;
  memset(&serv, 0, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(port);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  connect(fd, (struct sockaddr *)&serv, sizeof(serv));
  while (1) {
    char buf[1024];
    printf("请输入要发送的字符串: ");
    fgets(buf, sizeof(buf), stdin);
    write(fd, buf, strlen(buf));

    int len = read(fd, buf, sizeof(buf));
    if (len == -1) {
      perror("read error");
    } else if (len == 0) {
      printf("服务器关闭了连接");
      break;
    } else {
      printf("recv buf: %s\n", buf);
    }
  }
  close(fd);
  return 0;
}
