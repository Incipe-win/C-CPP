#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  if (access(argv[1], R_OK) == 0) {
    printf("%s read is ok!\n", argv[1]);
  }
  if (access(argv[1], W_OK) == 0) {
    printf("%s wirte is ok!\n", argv[1]);
  }
  if (access(argv[1], X_OK) == 0) {
    printf("%s exe is ok!\n", argv[1]);
  }
  if (access(argv[1], F_OK) == 0) {
    printf("%s file exists!\n", argv[1]);
  }
  return 0;
}
