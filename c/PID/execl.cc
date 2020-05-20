#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  execl("./fep", "fep", NULL);
  perror("execl error");
  printf("Bye Bye!");
  return 0;
}
