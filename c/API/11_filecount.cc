#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int count = 0;

int dirCount(char *dirname) {
  // 打印路径
  printf("%s\n", dirname);
  // 打开目录
  DIR *dirp = opendir(dirname);
  if (dirp == NULL) {
    perror("opendir err: ");
    return -1;
  }
  struct dirent *dentp = NULL;
  // 循环读目录，遇到普通文件个数++
  while ((dentp = readdir(dirp)) != NULL) {
    // 如果是目录
    if (dentp->d_type == DT_DIR) {
      // 遇到'.', '..'就跳过
      if (strcmp(".", dentp->d_name) == 0 || strcmp("..", dentp->d_name) == 0) {
        continue;
      }
      // 拼接新路径，递归找文件
      char newdirname[257] = {0};
      sprintf(newdirname, "%s/%s", dirname, dentp->d_name);
      dirCount(newdirname);
    }
    // 是文件
    if (dentp->d_type == DT_REG) {
      ++count;
      // 打印文件名字
      printf("dname : %s\n", dentp->d_name);
    }
  }
  // 关闭目录
  closedir(dirp);
  return count;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./.a.out filename\n");
    return -1;
  }
  dirCount(argv[1]);
  printf("count = %d\n", count);
  return 0;
}
