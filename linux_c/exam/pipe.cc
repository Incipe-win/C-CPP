#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int fd[2];
  // 创建管道
  if (pipe(fd) < 0) {
    perror("pipe error: ");
    exit(-1);
  }
  pid_t pid;
  if ((pid = fork()) < 0) {
    perror("fork error: ");
    exit(-1);
  } else if (pid == 0) {
    // 子进程只负责写，关闭读端
    close(fd[0]);
    // 把屏幕输出重定向到管道的写端
    dup2(fd[1], STDOUT_FILENO);
    // 利用execlp执行shell命令
    execlp("ps", "ps", "-aux", NULL);
  } else {
    int status;
    if (wait(&status) < 0) {
      perror("wait error: ");
      exit(-1);
    }
    if (WIFEXITED(status)) {
      printf("child exit with %d\n", WEXITSTATUS(status));
    }
    if (WIFSIGNALED(status)) {
      printf("child exit by %d\n", WTERMSIG(status));
    }
    // 父进程负责读，关闭写端
    close(fd[1]);
    // 把终端输入的信息重定向到管道的读端
    dup2(fd[0], STDIN_FILENO);
    system("grep msql3d");
    // execlp("grep", "grep", "msql3d", NULL);
  }
  return 0;
}
