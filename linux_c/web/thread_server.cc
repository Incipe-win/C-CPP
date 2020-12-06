#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct _SockInfo {
  pthread_t id;
  int fd;
  struct sockaddr_in server;
} SockInfo;

void *worker(void *data) {
  SockInfo *info = (SockInfo *)data;
  char ipbuf[64];
  memset(ipbuf, 0, sizeof(ipbuf));
  printf(
      "客户端: %s, 端口: %d连接\n",
      inet_ntop(AF_INET, &info->server.sin_addr.s_addr, ipbuf, sizeof(ipbuf)),
      htons(info->server.sin_port));
  while (1) {
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    int len = read(info->fd, buf, sizeof(buf));
    if (len == -1) {
      perror("read error");
      pthread_exit(NULL);
    } else if (len == 0) {
      printf("客户端%s断开连接\n", ipbuf);
      close(info->fd);
      break;
    } else {
      printf("客户端%s发送的消息: %s\n", ipbuf, buf);
      for (int i = 0; i < len; ++i) {
        buf[i] = toupper(buf[i]);
      }
      write(info->fd, buf, sizeof(buf));
    }
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out port\n");
    exit(-1);
  }
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  if (lfd < 0) {
    perror("sock error");
    exit(-1);
  }
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[1]));
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  int ret = bind(lfd, (struct sockaddr *)&server, sizeof(server));
  if (ret < 0) {
    perror("bind error");
    exit(-1);
  }
  ret = listen(lfd, 128);
  if (ret < 0) {
    perror("listen error");
    exit(-1);
  }
  SockInfo info[256];
  for (int j = 0; j < (int)(sizeof(info) / sizeof(info[0])); ++j) {
    info[j].fd = -1;
  }
  socklen_t len = sizeof(struct sockaddr_in);
  while (1) {
    int i;
    for (i = 0; i < (int)(sizeof(info) / sizeof(info[0])); ++i) {
      if (info[i].fd == -1) {
        break;
      }
    }
    if (i == 256) {
      break;
    }
    info[i].fd = accept(lfd, (struct sockaddr *)&info[i].server, &len);
    pthread_create(&info[i].id, NULL, worker, &info[i]);
    pthread_detach(info[i].id);
  }
  close(lfd);
  pthread_exit(NULL);
  return 0;
}
