#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("homepath is [%s]\n", getenv("HOME"));
  return 0;
}
