#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main() {
  int fd[2];
  pid_t pid;
  if (pipe(fd) < 0) {
    perror("pipe: ");
    exit(1);
  }
  if ((pid = fork()) < 0) {
    perror("fork: ");
    exit(1);
  } else if (pid == 0) {
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    execlp("ps", "ps", "-aux", NULL);
  }
  if ((pid = fork()) < 0) {
    perror("fork: ");
    exit(1);
  } else if (pid == 0) {
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    execlp("grep", "grep", "zsh", NULL);
  } else {
    close(fd[0]);
    close(fd[1]);
    for (int i = 0; i < 2; ++i) {
      pid_t wpid = wait(NULL);
      printf("wpid = %d\n", wpid);
    }
  }
  return 0;
}
