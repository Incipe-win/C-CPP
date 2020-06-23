#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void *print(void *arg) {
  printf("I am thread, tid = %lu\n", pthread_self());
  sleep(4);
  return NULL;
}

int main() {
  pthread_t tid;
  pthread_create(&tid, NULL, print, NULL);
  printf("I am main thread, tid = %lu\n", pthread_self());
  sleep(5);
  pthread_detach(tid);
  int ret = 0;
  if ((ret = pthread_join(tid, NULL)) > 0) {
    printf("join error: %d, %s\n", ret, strerror(ret));
  }
  return 0;
}
