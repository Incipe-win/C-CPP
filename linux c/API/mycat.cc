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
  int fd = open(argv[1], O_RDONLY);
  char buf[250];
  int ret = read(fd, buf, sizeof(buf));
  write(STDOUT_FILENO, buf, ret);
  while (ret) {
    ret = read(fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, ret);
  }
  close(fd);
  return 0;
}
