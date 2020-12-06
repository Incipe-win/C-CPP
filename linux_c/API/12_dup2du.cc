#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 复制文件描述符1
  int outfd = dup(1);
  int fd = open("world", O_WRONLY | O_CREAT, 0666);
  // 标准输出到fd文件描述符
  dup2(fd, 1);
  printf("Hello World!\n");
  close(fd);
  fflush(stdout);
  // 恢复，重新对应标准输出
  dup2(outfd, 1);
  printf("Hello World!\n");
  return 0;
}
