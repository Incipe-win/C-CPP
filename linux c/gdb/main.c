#include <stdio.h>

extern int fib(int);

int main() {
  printf("fib = %d\n", fib(10));
  return 0;
}
