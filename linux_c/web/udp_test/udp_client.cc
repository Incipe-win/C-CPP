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
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[1]));
  inet_pton(AF_INET, "127.0.0.1", &server.sin_addr.s_addr);
  char buf[1024];
  while (1) {
    memset(buf, 0, sizeof(buf));
    printf("send message: ");
    fgets(buf, sizeof(buf), stdin);
    if ((sendto(lfd, buf, sizeof(buf), 0, (struct sockaddr *)&server,
                sizeof(server))) < 0) {
      perror("recvfrom error: ");
      exit(-1);
    }
    recvfrom(lfd, buf, sizeof(buf), 0, NULL, NULL);
    printf("recv message is %s\n", buf);
  }
  close(lfd);
  return 0;
}
