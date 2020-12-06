#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include <iostream>

void *print(void *arg) {
  printf("I am a thread, tid = %lu\n", pthread_self());
  // return NULL;
  int *x = new int(100);
  // std::cout << (int *)x << std::endl;
  // delete ret;
  // ret = NULL;
  // int *ret = NULL;
  // *ret = 100;
  // std::cout << (void *)x << std::endl;
  return (void *)x;
}

int main() {
  pthread_t tid;
  pthread_create(&tid, NULL, print, NULL);
  printf("I am main thread, tid = %lu\n", pthread_self());
  void *ret = NULL;
  pthread_join(tid, &ret);
  std::cout << "&ret = " << &ret << std::endl;
  std::cout << "&*(int *)ret = " << &*(int *)ret << std::endl;
  std::cout << "ret = " << ret << std::endl;
  std::cout << "(void *)ret = " << (void *)ret << std::endl;
  std::cout << "*(int *)ret = " << *(int *)ret << std::endl;
  // printf("ret = %d\n", *(int *)ret);
  return 0;
}
