#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

unsigned char *read_file(char *filepath) {
  int fd = 0;
  fd = open(filepath, O_RDONLY);
  if (fd == -1) {
    perror("file open error: ");
    exit(-1);
  }
  unsigned char buf[32] = {0};
  read(fd, buf, sizeof(buf));
  return buf;
}
