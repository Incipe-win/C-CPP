#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int num = 1000;
// pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
pthread_rwlock_t rwlock;

void *func_write(void *data) {
  while (1) {
    pthread_rwlock_wrlock(&rwlock);
    printf("---%s---self---%lu---num---%d\n", __FUNCTION__, pthread_self(),
           ++num);
    usleep(2000);
    pthread_rwlock_unlock(&rwlock);
    usleep(3000);
  }
  return NULL;
}

void *func_read(void *data) {
  while (1) {
    pthread_rwlock_rdlock(&rwlock);
    printf("---%s---self---%lu---num---%d\n", __FUNCTION__, pthread_self(),
           num);
    usleep(2000);
    pthread_rwlock_unlock(&rwlock);
    usleep(2000);
  }
  return NULL;
}

int main() {
  pthread_rwlock_init(&rwlock, NULL);
  int n = 8, i = 0;
  pthread_t thread[n];  // -read 5 write 3
  for (i = 0; i < 5; ++i) {
    pthread_create(&thread[i], NULL, func_read, NULL);
  }
  for (; i < n; ++i) {
    pthread_create(&thread[i], NULL, func_write, NULL);
  }
  for (i = 0; i < n; ++i) {
    pthread_join(thread[i], NULL);
  }
  return 0;
}
