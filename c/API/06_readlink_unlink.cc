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
  char buf[32] = {0};
  // 只能读取软链接
  readlink(argv[1], buf, sizeof(buf));
  printf("buf is %s\n", buf);
  // 软硬都可以
  // 还可以删除文件
  unlink(argv[1]);
  return 0;
}
