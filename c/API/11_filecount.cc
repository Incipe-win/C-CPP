#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int count = 0;

int dirCount(char *dirname) {
  printf("%s\n", dirname);
  DIR *dirp = opendir(dirname);
  if (dirp == NULL) {
    perror("opendir err: ");
    return -1;
  }
  struct dirent *dentp = NULL;
  while ((dentp = readdir(dirp)) != NULL) {
    if (dentp->d_type == DT_DIR) {
      if (strcmp(".", dentp->d_name) == 0 || strcmp("..", dentp->d_name) == 0) {
        continue;
      }
      char newdirname[257] = {0};
      sprintf(newdirname, "%s/%s", dirname, dentp->d_name);
      dirCount(newdirname);
    }
    if (dentp->d_type == DT_REG) {
      ++count;
      printf("dname : %s\n", dentp->d_name);
    }
  }
  closedir(dirp);
  return count;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./.a.out filename\n");
    return -1;
  }
  // 打开目录
  // 循环读目录，遇到普通文件个数++
  // 关闭目录
  dirCount(argv[1]);
  printf("count = %d\n", count);
  return 0;
}
