#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  printf("open begin...\n");
  int fd = open(argv[1], O_RDONLY);
  printf("open end...\n");
  char buf[256];
  while (1) {
    int ret = read(fd, buf, sizeof(buf));
    printf("read: %s\n", buf);
    if (ret == 0) {
      break;
    }
  }
  close(fd);
  return 0;
}
