#include <stdio.h>
#include <stdlib.h>

int main() {
  for (int i = 0x1; i <= 0xf; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%x*%x=%-4x", i, j, i * j);
    }
    printf("\n");
  }
  system("pause");
  return 0;
}