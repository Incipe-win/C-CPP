#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  int fd = open(argv[1], O_RDONLY | O_CREAT, 0666);
  unlink(argv[1]);
  int ret = write(fd, "world", 5);
  if (ret > 0) {
    printf("write ok!%d\n", ret);
  }
  if (ret < 0) {
    perror("write err: ");
  }
  close(fd);
  return 0;
}
