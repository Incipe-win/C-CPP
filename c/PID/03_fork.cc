#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error");
    exit(1);
  } else if (pid == 0) {
    // 子进程
    printf("我是子进程, 进程id = %d, 父进程id = %d\n", getpid(), getppid());
    while (1) {
      printf("我是子进程..., pid = %d, ppid = %d\n", getpid(), getppid());
      sleep(1);
    }
  } else {
    // 父进程
    printf("子进程id = %d, 进程id = %d, 父进程id = %d\n", pid, getpid(),
           getppid());
  }
  return 0;
}
