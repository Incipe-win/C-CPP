#include <arpa/inet.h>
#include <fcntl.h>
#include <linux/input.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "init_video.h"

int main(int argc, char *argv[]) {
  // open video with pthread
  pthread_t tid;
  pthread_create(&tid, NULL, get_bmp, NULL);
  pthread_join(tid, NULL);
  return 0;
}
