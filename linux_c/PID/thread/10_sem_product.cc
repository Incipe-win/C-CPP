#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t blank, xfull;

int que[5];
int num = 1000;

void *producter(void *data) {
  int i = 0;
  while (1) {
    sem_wait(&blank);
    printf("---%s---%lu---%d\n", __FUNCTION__, pthread_self(), num);
    que[i % 5] = num++;
    ++i;
    sem_post(&xfull);
    sleep(rand() % 2);
  }
  return NULL;
}

void *customer(void *data) {
  int i = 0;
  while (1) {
    sem_wait(&xfull);
    i %= 5;
    printf("---%s---%lu---%d\n", __FUNCTION__, pthread_self(), que[i]);
    ++i;
    sem_post(&blank);
    sleep(rand() % 3);
  }
  return NULL;
}

int main() {
  sem_init(&blank, 0, 5);
  sem_init(&xfull, 0, 0);
  int n = 2;
  pthread_t thread[n];
  pthread_create(&thread[0], NULL, producter, NULL);
  pthread_create(&thread[1], NULL, customer, NULL);
  for (int i = 0; i < n; ++i) {
    pthread_join(thread[i], NULL);
  }
  sem_destroy(&blank);
  sem_destroy(&xfull);
  return 0;
}
