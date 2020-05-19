#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("Begin...\n");
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error");
    exit(1);
  } else if (pid == 0) {
    // 子进程
    printf("I am a child fork, pid = %d, ppid = %d\n", getpid(), getppid());
    while (1) {
      printf("I am a child fork\n");
      sleep(1);
    }
  } else {
    // 父进程
    printf("childpid = %d, self = %d, ppid = %d\n", pid, getpid(), getppid());
    while (1) {
      sleep(1);
    }
  }
  printf("End...\n");

  return 0;
}
