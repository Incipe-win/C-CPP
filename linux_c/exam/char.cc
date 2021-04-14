#include <stdio.h>
#include <stdlib.h>

int main() {
  char c = 250;
  unsigned char d;
  char f;
  d = c + 249;
  f = c + 249;
  printf("d = %d\n", d);
  printf("d = %u\n", d);
  printf("f = %d\n", f);
  printf("f = %u\n", f);
  return 0;
}
