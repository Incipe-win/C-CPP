#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int fd[2];

void func(int num) {
  printf("catch a %d signal\n", num);
  // 父进程负责读，关闭写端
  close(fd[1]);
  // 把终端输入的信息重定向到管道的读端
  dup2(fd[0], STDIN_FILENO);
  char buf[1024];
  // 读管道
  read(STDIN_FILENO, buf, sizeof(buf));
  printf("buf is %s\n", buf);
}

int main() {
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
    while (1) {
      const char *buf = "hello world ";
      // 写管道
      write(STDOUT_FILENO, buf, strlen(buf));
      sleep(1);
    }
  } else {
    // 定义闹钟信号
    signal(SIGALRM, func);
    // 第一次产生闹钟是5秒后，之后每隔3秒产生一次闹钟
    struct itimerval it = {{3, 0}, {5, 0}};
    // 周期性的产生信号, ITIMER_REAL 自然定时，对应信号SIGALRM
    setitimer(ITIMER_REAL, &it, NULL);
    while (1) {
      printf("...\n");
      sleep(1);
    }
  }
  return 0;
}
