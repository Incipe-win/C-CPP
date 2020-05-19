#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int n = 5;
  int i;
  pid_t pid;
  for (i = 0; i < n; ++i) {
    pid = fork();
    if (pid < 0) {
      perror("fork err");
      exit(1);
    }
    if (pid == 0) {
      break;
    }
  }
  if (i == 5) {
    printf("I am parent process, pid = %d\n", getpid());
    while (1) {
      pid_t wpid = waitpid(-1, NULL, WNOHANG);
      if (wpid == -1) {
        break;
      } else if (wpid > 0) {
        printf("wpid = %d\n", wpid);
      }
    }
    while (1) {
      sleep(1);
    }
  }
  if (i < 5) {
    sleep(i);
    printf("I am child process, pid = %d, ppid = %d\n", getpid(), getppid());
  }
}
