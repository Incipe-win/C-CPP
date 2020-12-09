#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define _FILE_NAME_ "/home/incipe/Desktop/temp.lock"

int main() {
  int fd;
  if ((fd = open(_FILE_NAME_, O_RDWR | O_CREAT, 0666)) < 0) {
    perror("open error: ");
    return -1;
  }
  struct flock lk;
  lk.l_type = F_WRLCK;
  lk.l_whence = SEEK_SET;
  lk.l_start = 0;
  lk.l_len = 0;
  if (fcntl(fd, F_SETLK, &lk) < 0) {
    perror("get lock error: ");
    exit(-1);
  }
  while (1) {
    printf("I am alive\n");
    sleep(1);
  }
  return 0;
}
