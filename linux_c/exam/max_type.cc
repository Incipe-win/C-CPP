#include <limits.h>
#include <stdio.h>

int main() {
  printf("char max is %d\n", CHAR_MAX);
  printf("char min is %d\n", CHAR_MIN);
  printf("unsigned char max is %d\n", UCHAR_MAX);
  unsigned char ch = -1;
  printf("ch is %u\n", ch);
  char ch1 = -13;
  printf("ch1 is %u\n", ch1);
  return 0;
}
