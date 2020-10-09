#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t empty, full;
const int SEM_CNT = 5;
int begin_num = 100;
int array[SEM_CNT];

void *producter(void *arg) {
  int i = 0;
  while (1) {
    sem_wait(&empty);
    printf("---%s---self: %lu---num---%d\n", __FUNCTION__, pthread_self(),
           begin_num);
    array[(i++) % SEM_CNT] = begin_num++;
    sem_post(&full);
    sleep(rand() % 3);
  }
  return NULL;
}

void *customer(void *arg) {
  int i = 0;
  int num = 0;
  while (1) {
    sem_wait(&full);
    num = array[(i++) % SEM_CNT];
    printf("---%s---self: %lu---num---%d\n", __FUNCTION__, pthread_self(), num);
    sem_post(&empty);
    sleep(rand() % 3);
  }
  return NULL;
}

int main() {
  sem_init(&empty, 0, SEM_CNT);
  sem_init(&full, 0, 0);

  pthread_t tid[2];
  pthread_create(&tid[0], NULL, producter, NULL);
  pthread_create(&tid[1], NULL, customer, NULL);
  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);

  sem_destroy(&empty);
  sem_destroy(&full);
  return 0;
}
