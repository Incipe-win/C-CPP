#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  int fd = 0;
  fd = open(argv[1], O_RDWR | O_CREAT, 0666);
  if (fd == -1) {
    perror("open file error: ");
    return -1;
  }
  const char *buf = "hello world\n";
  write(fd, buf, strlen(buf));
  close(fd);
  return 0;
}
