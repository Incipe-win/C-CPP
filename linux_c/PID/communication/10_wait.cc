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
    printf("I am child, will die, pid = %d, ppid = %d\n", getpid(), getppid());
    sleep(2);
    while (1) {
      printf("I am child, please die me\n");
      sleep(1);
    }
    // return 101;
    // exit(102);
  } else {
    printf("I am parent, wait child die!\n");
    int status;
    // 子进程没死，会陷入阻塞
    pid_t wpid = wait(&status);
    printf("wait ok, wpid = %d, pid = %d\n", wpid, pid);
    if (WIFEXITED(status)) {
      printf("child exit with %d\n", WEXITSTATUS(status));
    }
    if (WIFSIGNALED(status)) {
      printf("child exit by %d\n", WTERMSIG(status));
    }
  }
  return 0;
}
