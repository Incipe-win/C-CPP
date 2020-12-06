#include <stdio.h>
#include <unistd.h>

int main() {
  int fd[2];
  pipe(fd);
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
  } else if (pid == 0) {
    printf("I am a child process, pid = %d, ppid = %d\n", getpid(), getppid());
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    execlp("ps", "ps", "-aux", NULL);
  } else {
    printf("I am a parent process, pid = %d\n", getpid());
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    execlp("grep", "grep", "zsh", NULL);
  }
  return 0;
}
