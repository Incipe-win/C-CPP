#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *print(void *arg) {
  while (1) {
    printf("I am a thread, tid = %lu\n", pthread_self());
    sleep(1);
  }
  return NULL;
}

int main() {
  pthread_t tid;
  pthread_create(&tid, NULL, print, NULL);
  sleep(5);
  if (pthread_cancel(tid) == 0) {
    printf("success!\n");
  } else {
    perror("fault...");
  }
  void *ret;
  pthread_join(tid, &ret);
  printf("ret = %d\n", *(int *)ret);
  return 0;
}
