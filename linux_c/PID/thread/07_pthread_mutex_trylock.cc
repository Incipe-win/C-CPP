#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *func(void *data) {
  while (1) {
    pthread_mutex_lock(&mutex);
    printf("Hello World\n");
    sleep(10);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

int main() {
  pthread_mutex_init(&mutex, NULL);
  pthread_t thread;
  pthread_create(&thread, NULL, func, NULL);
  // pthread_join(thread, NULL);
  sleep(1);
  while (1) {
    int ret;
    if ((ret = pthread_mutex_trylock(&mutex)) > 0) {
      printf("ret %d, msgerror %s\n", ret, strerror(ret));
    }
    sleep(1);
  }
  return 0;
}
