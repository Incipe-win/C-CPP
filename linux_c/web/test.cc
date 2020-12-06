#include <stdio.h>
#include <stdlib.h>

union {
  short s;
  char c[sizeof(short)];
} un2;

union {
  int s;
  char c[sizeof(int)];
} un4;

int main() {
  printf("[%lu][%lu][%lu]\n", sizeof(short), sizeof(int), sizeof(long int));

  un2.s = 0x0102;
  printf("%d, %d, %d\n", un2.c[0], un2.c[1], un2.s);

  un4.s = 0x01020304;
  printf("%d, %d, %d, %d, %d\n", un4.c[0], un4.c[1], un4.c[2], un4.c[3], un4.s);
  return 0;
}
