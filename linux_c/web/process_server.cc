#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void recyle(int num) {
  pid_t pid;
  while ((pid = waitpid(-1, NULL, WNOHANG)) > 0) {
    printf("child died, pid = %d\n", pid);
  }
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

  struct sigaction act;
  act.sa_handler = recyle;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
  sigaction(SIGCHLD, &act, NULL);

  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  while (1) {
    int cfd = accept(lfd, (struct sockaddr *)&client, &len);
    if (cfd == -1 && errno == EINTR) {
      cfd = accept(lfd, (struct sockaddr *)&client, &len);
    }
    pid_t pid;
    if ((pid = fork()) < 0) {
      perror("fork error");
      exit(-1);
    } else if (pid == 0) {
      close(lfd);
      char ipbuf[64];
      memset(ipbuf, 0, sizeof(ipbuf));
      printf("客户端: %s, 端口: %d连接\n",
             inet_ntop(AF_INET, &client.sin_addr.s_addr, ipbuf, sizeof(ipbuf)),
             ntohs(client.sin_port));
      while (1) {
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        int n = read(cfd, buf, sizeof(buf));
        if (n < 0) {
          perror("read error");
          exit(-1);
        } else if (n == 0) {
          printf("客户端: %s断开连接\n", ipbuf);
          close(cfd);
          break;
        } else {
          printf("接受到客户端: %s的数据: %s", ipbuf, buf);
          for (int i = 0; i < n; ++i) {
            buf[i] = toupper(buf[i]);
          }
          write(cfd, buf, n);
        }
      }
      exit(0);
    } else {
      close(cfd);
    }
  }
  close(lfd);
  return 0;
}
