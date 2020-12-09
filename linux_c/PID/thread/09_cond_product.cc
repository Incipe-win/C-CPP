#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int num = 1000;

typedef struct _ProductInfo {
  int num;
  struct _ProductInfo *next;
} ProductInfo;

ProductInfo *head = NULL;

void *producter(void *data) {
  while (1) {
    ProductInfo *info = (ProductInfo *)malloc(sizeof(ProductInfo));
    info->num = num++;
    printf("---%s---%lu---%d\n", __FUNCTION__, pthread_self(), info->num);
    pthread_mutex_lock(&mutex);
    info->next = head;
    head = info;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    sleep(rand() % 2);
  }
  return NULL;
}

void *customer(void *data) {
  ProductInfo *info = NULL;
  while (1) {
    pthread_mutex_lock(&mutex);
    // if (head == NULL) {
    while (!head) {
      pthread_cond_wait(&cond, &mutex);
    }
    info = head;
    head = head->next;
    printf("---%s---%lu---%d\n", __FUNCTION__, pthread_self(), info->num);
    pthread_mutex_unlock(&mutex);
    sleep(rand() % 4);
    free(info);
  }
  return NULL;
}

int main() {
  pthread_t thread[3];
  pthread_create(&thread[0], NULL, producter, NULL);
  pthread_create(&thread[1], NULL, customer, NULL);
  pthread_create(&thread[2], NULL, customer, NULL);
  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);
  pthread_join(thread[2], NULL);
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
  return 0;
}
