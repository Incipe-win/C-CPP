#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // 确保当前路径有fifo有名管道文件
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  printf("open begin...\n");
  int fd = open(argv[1], O_WRONLY);
  printf("open end...\n");
  char buf[256];
  int num = 1;
  while (1) {
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "fifo%04d", num++);
    write(fd, buf, sizeof(buf));
    sleep(1);
    if (num == 100) {
      break;
    }
  }
  close(fd);
  return 0;
}
