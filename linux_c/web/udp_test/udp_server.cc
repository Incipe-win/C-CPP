#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out port\n");
    return 0;
  }
  int lfd;
  if ((lfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket error: ");
    exit(-1);
  }

  struct sockaddr_in server;
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[1]));
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(lfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind error: ");
    exit(-1);
  }
  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  char buf[1024];
  char ipbuf[64];
  while (1) {
    memset(buf, 0, sizeof(buf));
    memset(ipbuf, 0, sizeof(ipbuf));
    if (recvfrom(lfd, buf, sizeof(buf), 0, (struct sockaddr *)&client, &len) <
        0) {
      perror("recvfrom error: ");
      exit(-1);
    }
    printf("connect success, client ip is %s, port is %d\n",
           inet_ntop(AF_INET, &client.sin_addr.s_addr, ipbuf, sizeof(ipbuf)),
           ntohs(client.sin_port));
    for (int i = 0; i < (int)strlen(buf); ++i) {
      buf[i] = toupper(buf[i]);
    }
    printf("send message: %s\n", buf);
    sendto(lfd, buf, sizeof(buf), 0, (struct sockaddr *)&client,
           sizeof(client));
  }
  close(lfd);
  return 0;
}
