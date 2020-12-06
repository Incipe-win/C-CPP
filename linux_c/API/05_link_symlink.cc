#include <fcntl.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  // char *newhard = (char *)malloc(sizeof(argv[1]) * 2);
  // strcpy(newhard, argv[1]);
  // strcat(newhard, ".hard");
  // // puts(newhard);
  // link(argv[1], newhard);
  char *newsoft = (char *)malloc(sizeof(argv[1]) * 2);
  strcpy(newsoft, argv[1]);
  strcat(newsoft, ".soft");
  symlink(argv[1], newsoft);
  return 0;
}
