#include <arpa/inet.h>
#include <ctype.h>
#include <poll.h>
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
  char ipbuf[64];

  struct pollfd allfd[1024];
  int max_index = 0;
  for (int i = 0; i < 1024; ++i) {
    allfd[i].fd = -1;
    allfd[i].events = POLLIN;
  }
  allfd[0].fd = lfd;

  while (1) {
    int i = 0;
    ret = poll(allfd, max_index + 1, -1);
    if (ret < 0) {
      perror("poll error: ");
      exit(-1);
    }

    if (allfd[0].revents & POLLIN) {
      int cfd = accept(lfd, (struct sockaddr *)&client, &len);
      if (cfd < 0) {
        perror("accept error: ");
        exit(-1);
      }
      memset(ipbuf, 0, sizeof(ipbuf));
      printf("connect success, client ip %s, port %d\n",
             inet_ntop(AF_INET, &client.sin_addr.s_addr, ipbuf, sizeof(ipbuf)),
             ntohs(client.sin_port));
      for (i = 0; i < 1024; ++i) {
        if (allfd[i].fd == -1) {
          allfd[i].fd = cfd;
          break;
        }
      }
      max_index = max_index < i ? i : max_index;
    }

    for (i = 1; i <= max_index; ++i) {
      int fd = allfd[i].fd;
      if (fd == -1) {
        continue;
      }
      if (allfd[i].revents & POLLIN) {
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        int n = recv(fd, buf, sizeof(buf), 0);
        if (n == -1) {
          perror("recv error: ");
          exit(-1);
        } else if (n == 0) {
          printf("client disconnect\n");
          close(fd);
        } else {
          printf("recv message: %s\n", buf);
          for (int j = 0; j < n; ++j) {
            buf[j] = toupper(buf[j]);
          }
          printf("send message: %s\n", buf);
          send(fd, buf, sizeof(buf), 0);
        }
      }
    }
  }
  close(lfd);
  return 0;
}
