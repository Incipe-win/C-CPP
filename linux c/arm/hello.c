#include <stdio.h>

// #define __def__

int main() {
#ifdef __def__
  printf("Hello\n");
#endif
  printf("Hello World\n");
  return 0;
}
