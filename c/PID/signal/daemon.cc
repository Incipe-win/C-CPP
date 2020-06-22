#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int i = 0;

void print(int num) { printf("i = %d\n", i++); }

int main() {
  // 创建子进程，父进程退出
  pid_t pid = fork();
  if (pid > 0) {
    exit(1);
  }
  // 当会长
  setsid();
  // 设置掩码
  umask(0);
  // 切换目录
  chdir(getenv("HOME"));
  // 关闭文件描述符
  // close(1);
  // close(2);
  // close(3);
  // 执行核心逻辑
  struct itimerval myit = {{1, 0}, {1, 0}};
  setitimer(ITIMER_REAL, &myit, NULL);
  struct sigaction act;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
  act.sa_handler = print;
  sigaction(SIGALRM, &act, NULL);
  while (1) {
    sleep(1);
  }
  // 退出
  return 0;
}
