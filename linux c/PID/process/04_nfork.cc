#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int n = 5;
  pid_t pid = 0;
  int i;
  for (i = 0; i < n; ++i) {
    pid = fork();
    if (pid < 0) {
      perror("fork error");
    } else if (pid == 0) {
      // 子进程
      printf("I am a child fork, pid = %d, ppid = %d\n", getpid(), getppid());
      break;  // 子进程结束
    } else {
      // 父进程
      printf("I am a father fork, pid = %d, ppid = %d\n", getpid(), getpid());
    }
  }
  sleep(i);
  if (i < 5) {
    printf("I am a child fork, will exit, pid = %d, ppid = %d\n", getpid(),
           getppid());
  } else {
    printf("I am a father fork, will out, pid = %d, ppid = %d\n", getpid(),
           getppid());
  }
  return 0;
}
