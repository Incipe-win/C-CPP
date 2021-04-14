#include <fcntl.h>
#include <linux/input.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <string>

using namespace std;

void mydaemon() {
  struct input_event vEvent;
  int fd, tmp_fd;
  fd = open("/dev/input/event1", O_RDONLY);
  if (fd < 0) {
    perror("open fault");
    exit(-1);
  }
  tmp_fd = open("/home/incipe/test.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);
  if (tmp_fd < 0) {
    perror("tmp_fd fault");
    exit(-1);
  }
  pid_t pid;
  if ((pid = fork()) < 0) {
    perror("fork error");
    exit(-1);
  } else if (pid > 0) {
    exit(1);
  }
  setsid();
  umask(0);
  chdir("/");
  close(0);
  close(1);
  close(2);
  // signal(SIGCHLD, SIG_DFL);
  while (1) {
    int ret = 0;
    ret = read(fd, &vEvent, sizeof(vEvent));
    char buf[100];
    sprintf(buf, "type = %d, code = %d, value = %d", vEvent.type, vEvent.code,
            vEvent.value);
    write(tmp_fd, buf, strlen(buf));
    sleep(10);
  }
  close(tmp_fd);
  close(fd);
}

int main() {
  mydaemon();
  return 0;
}
