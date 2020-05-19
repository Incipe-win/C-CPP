#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
    exit(1);
  } else if (pid == 0) {
    while (1) {
      sleep(1);
    }
  } else {
    sleep(1);
  }
}
