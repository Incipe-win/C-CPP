#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int var = 100;

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    printf("child, var = %d, pid = %d, ppid = %d\n", var, getpid(), getppid());
    var = 1001;
    printf("child, var = %d, pid = %d, ppid = %d\n", var, getpid(), getppid());
    sleep(3);
  } else if (pid > 0) {
    sleep(1);
    printf("parent, var = %d, pid = %d, ppid = %d\n", var, getpid(), getppid());
    var = 2000;
    printf("parent, var = %d, pid = %d, ppid = %d\n", var, getpid(), getppid());
  }
  return 0;
}
