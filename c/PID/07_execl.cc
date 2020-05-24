#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // execlp("ls", "ls", "-lrt", NULL);
  // 没有返回值
  execl("/bin/ls", "ls", "-lrt", NULL);
  perror("error fault");
  return 0;
}
