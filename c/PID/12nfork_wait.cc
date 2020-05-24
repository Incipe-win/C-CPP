#include <fcntl.h>
#include <stdio.h>
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
    if (pid == 0) {
      printf("I am a child process, pid = %d, ppid = %d\n", getpid(),
             getppid());
      break;
    }
  }
  sleep(i);
  if (i == 5) {
    printf("I am a parent process, pid = %d\n", getpid());
    for (i = 0; i < n; ++i) {
      pid_t wpid = wait(NULL);
      printf("wpid = %d\n", wpid);
    }
    // 防止产生孤儿进程
    while (1) {
      sleep(1);
    }
  }
  return 0;
}
