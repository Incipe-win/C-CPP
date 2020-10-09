#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  int fd = open(argv[1], O_RDWR);
  char *mem = (char *)mmap(NULL, 8, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (mem == MAP_FAILED) {
    perror("mmap error:");
    return -1;
  }
  strcpy(mem, "hello");
  if (munmap(mem, 8) < 0) {
    perror("munmap error:");
  }
  close(fd);
  return 0;
}
