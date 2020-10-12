#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("./a.out filename\n");
    return -1;
  }
  int fd = open(argv[2], O_RDWR | O_CREAT, 0666);
  write(fd, argv[1], strlen(argv[1]));
  write(fd, "\n", 1);
  // 此时文件已经到末尾了，需要移动读写位置
  lseek(fd, 0, SEEK_SET);
  char buf[256] = {0};
  int ret = read(fd, buf, sizeof(buf));
  write(STDOUT_FILENO, buf, ret);  // STDOUT_FILENO, STDIN_FILENO, STDERR_FILENO
  while (ret) {
    ret = read(fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, ret);
  }
  close(fd);
  return 0;
}
