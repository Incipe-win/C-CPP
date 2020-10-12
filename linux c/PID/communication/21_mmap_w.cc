#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct _Student {
  int sid;
  char sname[20];
} Student;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename");
    return -1;
  }
  int fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 0666);
  int length = sizeof(Student);
  ftruncate(fd, length);
  Student *stu =
      (Student *)mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (stu == MAP_FAILED) {
    perror("mmap error:");
    return -1;
  }
  int num = 1;
  while (1) {
    stu->sid = num;
    sprintf(stu->sname, "xiaoming%4d", num++);
    sleep(1);
  }
  munmap(stu, length);
  close(fd);
  return 0;
}
