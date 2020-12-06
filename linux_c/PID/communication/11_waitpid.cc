#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
    exit(1);
  } else if (pid == 0) {
    printf("I am child process, pid = %d, ppid = %d\n", getpid(), getppid());
    sleep(2);
  } else {
    printf("I am pather process, pid = %d, ppid = %d\n", getpid(), getppid());
    // 参数-1,不等待子进程结束，也就是不陷入阻塞态
    int ret;
    while ((ret = waitpid(-1, NULL, WNOHANG)) == 0) {
      sleep(1);
    }
    printf("ret = %d\n", ret);
    while (1) {
      sleep(1);
    }
  }
  return 0;
}
