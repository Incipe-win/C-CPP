#include <stdio.h>

int main() {
  int value;
  int ret1, ret2;
  while (((ret1 = scanf("%d", &value)) != 1) || (ret2 = getchar()) != '\n') {
    if (ret1 != 1 || ret2 != '\n')
      while (getchar() != '\n')
        ;
    printf("input invalid!\n");
  }
  return 0;
}