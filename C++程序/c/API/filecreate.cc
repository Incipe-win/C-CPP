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
  int fd = open(argv[1], O_WRONLY | O_CREAT, 0666);
  int ret = lseek(fd, 1024, SEEK_END);
  // 至少要写一次，才能创建指定大小文件
  write(fd, "\n", 1);
  close(fd);
  return 0;
}
