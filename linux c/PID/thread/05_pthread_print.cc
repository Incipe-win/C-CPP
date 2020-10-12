#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;

void *print1(void *arg) {
  while (1) {
    pthread_mutex_lock(&mutex);
    printf("hello");
    sleep(rand() % 3);
    printf("world\n");
    pthread_mutex_unlock(&mutex);
    sleep(rand() % 3);
  }
}

void *print2(void *arg) {
  while (1) {
    pthread_mutex_lock(&mutex);
    printf("HELLO");
    sleep(rand() % 3);
    printf("WORLD\n");
    pthread_mutex_unlock(&mutex);
    sleep(rand() % 3);
  }
}

int main() {
  pthread_t tid[2];
  pthread_create(&tid[0], NULL, print1, NULL);
  pthread_create(&tid[1], NULL, print2, NULL);
  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  return 0;
}
