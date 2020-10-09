#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
    exit(1);
  } else if (pid == 0) {
    printf("I am child process, pid = %d, ppid = %d\n", getpid(), getppid());
    sleep(2);
    printf("I am child, and i will die");
  } else {
    while (1) {
      printf("I am father process, pid = %d\n", getpid());
      sleep(1);
    }
  }
  // 杀死僵尸进程方法，把其父进程kill即可
  return 0;
}
