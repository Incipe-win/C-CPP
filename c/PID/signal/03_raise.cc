#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  sleep(1);
  raise(SIGKILL);
  return 0;
}
