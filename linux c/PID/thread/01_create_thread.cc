#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *print(void *argv) {
  printf("I am a thread, pid = %d, tid = %lu\n", getpid(), pthread_self());
  return argv;
}

int main() {
  pthread_t tid;
  pthread_create(&tid, NULL, print, NULL);
  printf("I am a main thread, pid = %d, tid = %lu\n", getpid(), pthread_self());
  sleep(1);
  return 0;
}
