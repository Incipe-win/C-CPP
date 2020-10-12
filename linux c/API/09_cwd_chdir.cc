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
  chdir(argv[1]);
  char buf[256];
  getcwd(buf, sizeof(buf));
  printf("buf is [%s]\n", buf);
  return 0;
}
