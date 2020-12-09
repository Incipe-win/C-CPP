#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("./a.out filename\n");
    return -1;
  }
  int fd = open(argv[1], O_CREAT | O_RDWR, 0666);
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
    exit(1);
  }
  if (pid == 0) {
    printf("I am child process, and i will write file, pid = %d, ppid = %d\n",
           getpid(), getppid());
    write(fd, argv[2], strlen(argv[2]));
  } else {
    int ret = 1;
    char buf[256] = {0};
    printf("I am parent process, and i will read file, pid = %d\n", getpid());
    while (ret) {
      ret = read(fd, buf, sizeof(buf));
    }
    // 防止僵尸进程，释放子进程资源
    pid_t wpid = wait(NULL);
    printf("waitpid wpid = %d\n", wpid);
    // 防止父进程先结束，形成孤儿进程, 可用守护进程
    while (1) {
      sleep(1);
    }
  }
  return 0;
}
