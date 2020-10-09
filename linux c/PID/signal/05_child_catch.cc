#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void catch_sig(int num) {
  pid_t wpid = waitpid(-1, NULL, WNOHANG);
  if (wpid > 0) {
    printf("wait child %d ok\n", wpid);
  }
}

int main() {
  int i = 0;
  pid_t pid;
  // 在创建子进程之前屏蔽SIGCHLD信号
  sigset_t myset, oldset;
  sigemptyset(&myset);
  sigaddset(&myset, SIGCHLD);
  // oldset保护现场，阻塞信号SIGCHLD，得到阻塞前的信号SIGCHLD
  sigprocmask(SIG_BLOCK, &myset, &oldset);
  for (i = 0; i < 10; ++i) {
    pid = fork();
    if (pid == 0) {
      break;
    }
  }
  if (i == 10) {
    struct sigaction act;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = catch_sig;
    sigaction(SIGCHLD, &act, NULL);
    sigprocmask(SIG_SETMASK, &oldset, NULL);
    while (1) {
      sleep(1);
    }
  } else if (i < 10) {
    printf("I am %d child, pid = %d\n", i, getpid());
    sleep(i);
  }
  return 0;
}
