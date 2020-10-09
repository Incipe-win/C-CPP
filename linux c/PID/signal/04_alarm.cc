#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  alarm(6);
  for (int i = 0; i < 6; ++i) {
    printf("i = %d\n", i);
    sleep(1);
  }
  return 0;
}
