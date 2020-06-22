#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void catch_signal(int num) { printf("catch a %d signal\n", num); }

int main() {
  signal(SIGALRM, catch_signal);
  struct itimerval myit = {{3, 0}, {5, 0}};
  setitimer(ITIMER_REAL, &myit, NULL);
  while (1) {
    printf("...\n");
    sleep(1);
  }
  return 0;
}
