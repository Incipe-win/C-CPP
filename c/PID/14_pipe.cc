#include <stdio.h>
#include <unistd.h>

int main() {
  int fd[2];
  pipe(fd);
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
  } else if (pid == 0) {
    printf("I am a child fork, pid = %d, ppid = %d\n", getpid(), getppid());
    write(fd[1], "hello", 5);
  } else {
    printf("I am a parent fork, pid = %d\n", getpid());
    char buf[12] = {0};
    int ret = read(fd[0], buf, sizeof(buf));
    if (ret > 0) {
      write(STDOUT_FILENO, buf, ret);
    }
  }
  return 0;
}
