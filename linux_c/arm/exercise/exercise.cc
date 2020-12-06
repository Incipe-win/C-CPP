#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    exit(-1);
  }
  int fd = 0;
  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("file open error: ");
    exit(-1);
  }
  unsigned char buf[32] = {0};
  read(fd, buf, sizeof(buf));
  return 0;
}
