#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  sigset_t pend;
  sigpending(&pend);
  for (int i = 1; i < 32; ++i) {
    if (sigismember(&pend, i) == 1) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
  return 0;
}
