#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("./a.out filename1 filename2\n");
    return -1;
  }
  int fd1 = open(argv[1], O_RDONLY);
  int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0666);
  char buf[256];
  int ret = read(fd1, buf, sizeof(buf));
  write(fd2, buf, ret);
  while (ret) {
    ret = read(fd1, buf, sizeof(buf));
    write(fd2, buf, ret);
  }
  close(fd1);
  close(fd2);
  return 0;
}
