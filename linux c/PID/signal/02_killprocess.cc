#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int i;
  for (i = 0; i < 5; ++i) {
    pid_t pid = fork();
    if (pid == 0) {
      break;
    }
  }
  if (i == 2) {
    printf("I am a child process\n");
    sleep(5);
    kill(getppid(), SIGKILL);
    while (1) {
      ;
    }
  } else if (i == 5) {
    printf("I am a father process\n");
    sleep(1);
  }
  return 0;
}
