#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int fd = open("./mem.txt", O_RDWR);
  int *mem = (int *)mmap(NULL, 8, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (mem == MAP_FAILED) {
    perror("mmap error:");
    return -1;
  }
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error:");
    return -1;
  } else if (pid == 0) {
    *mem = 100;
    printf("child, *mem = %d\n", *mem);
    sleep(3);
    printf("child, *mem = %d\n", *mem);
  } else {
    sleep(1);
    printf("parent, *mem = %d\n", *mem);
    *mem = 1001;
    printf("parent, *mem = %d\n", *mem);
    wait(NULL);
  }
  munmap(mem, 8);
  close(fd);
  return 0;
}
