#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int i;
  for (i = 0; i < 3; ++i) {
    if (fork() > 0) {
      break;
    }
  }
  while (1) {
    sleep(1);
  }
  return 0;
}
