#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *print(void *arg) {
  printf("I am a thread, tid = %lu\n", pthread_self());
  return (void *)100;
}

int main() {
  pthread_t tid;
  pthread_create(&tid, NULL, print, NULL);
  printf("I am main thread, tid = %lu\n", pthread_self());
  void *ret;
  pthread_join(tid, &ret);
  printf("ret = %p\n", ret);
  printf("ret = %d\n", (int)ret);
  return 0;
}
