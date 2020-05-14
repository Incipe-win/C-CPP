### 讲在前面的话

本文主要介绍几个主要的 **linux** 系统 **API**。

注：本文讲的简单，每个 **API** 举了一个例子，不适合深入学习，只适合忘记了某个函数来回顾下用法。

**系统API** 和 **C语言库函数** 区别：

简单的讲： **C库函数** 是由 **API** 封装而来的。每个系统的 **API** 都不一样，但是 **C库函数** 一样，库函数更具移植性。

### errno 错误报告

下文很多函数返回失败都要设置 **errno** ，这里解释明白。

更详细的可到 **linux** 这三个头文件查看。

````bash
/usr/include/asm-generic/errno-base.h 
/usr/include/asm-generic/errno.h
/usr/include/errno.h
````

C语言提供了 **perror** 和 **strerror** 函数来显示与 **error** 相关的错误信息。

+ **perror()** 函数显示您传给它的字符串，后跟一个冒号、一个空格和当前 **errno** 值的文本表示形式。
  + **perror("error is");**
+ **strerror()** 函数，返回一个指针，指针指向当前 **errno** 值的文本表示形式。
  + **fprintf(stderr, "error in CreateProcess %s", strerror(errno));**

### open打开文件

````bash
man 2 open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
````

#### 参数介绍

+ **pathname**  文件名；
+ **flags**
  + 必选项
    + **O_RDONLY**  只读
    + **O_WRONLY** 只写
    + **O_RDWR**  读写
  + 可选项
    + **O_APPEND** 追加
    + **O_CREAT** 创建文件
      + **O_EXCL** 与  **O_CREAT**  一起使用，如果文件存在，则报错。
      + **mode** 权限位，最终（ **mode & ~umask** ）
    + **O_NONBLOCK** 非阻塞 

#### 返回值

+ 返回最小的可用文件描述符
+ 失败返回-1，设置 **errno** 

### close关闭文件

````bash
man 2 close
#include <unistd.h>
int close(int fd);
````

#### 参数介绍

+ **fd** 文件描述符

#### 返回值

+ 成功0
+ 失败-1，设置 **errno**

### open 和 close 实现 touch

````cpp
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
  int fd = open(argv[1], O_RDONLY | O_CREAT, 0666);
  close(fd);
  return 0;
}
````

````bash
编译后执行
./a.out newfile.cc
即可创建newfile.cc文件
````

### read读取文件

````bash
man 2 read
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count);
````

#### 参数介绍

+ **fd** 文件描述符
+ **buf** 缓冲区
+ **count** 缓冲区大小

#### 返回值

+ 失败-1，设置 **errno** 

+ 成功返回读到的大小
+ **0** 代表读到文件末尾

### write写文件

````bash
man 2 write
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t count);
````

#### 参数介绍

+ **fd** 文件描述符
+ **buf** 缓冲区
+ **count** 大小

#### 返回值

+ 成功，返回写入的字节数
+ 失败，返回-1
+ 0代表未写入

### 利用 read 和 write 可实现 cat

````cpp
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
  int fd = open(argv[1], O_RDONLY);
  char buf[250];
  int ret = read(fd, buf, sizeof(buf));
  write(STDOUT_FILENO, buf, ret);
  while (ret) {
    ret = read(fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, ret);
  }
  close(fd);
  return 0;
}
````

````bash
默认打开的三个文件描述符
STDOUT_FILENO	0
STDIN_FILENO	1
STDERR_FILENO	2
````

请戳 [文件描述符]([https://baike.baidu.com/item/%E6%96%87%E4%BB%B6%E6%8F%8F%E8%BF%B0%E7%AC%A6](https://baike.baidu.com/item/文件描述符)) 

### lseek

````bash
man 2 lseek
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
````

#### 参数介绍

+ **fd** 文件描述符
+ **offset** [偏移量]([https://baike.baidu.com/item/%E5%81%8F%E7%A7%BB%E9%87%8F](https://baike.baidu.com/item/偏移量))
+ **whence**
  + **SEEK_SET**  文件开始位置
  + **SEEK_CUR**  文件当前位置
  + **SEEK_END** 文件结尾

#### 返回值

+ 成功：返回当前位置到开始的长度
+ 失败-1，设置 **errno**

#### lseek作用：

+ 移动文件读写位置
+ 计算文件大小
+ 扩展文件

#### 利用lseek移动读写文件位置

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("./a.out filename\n");
    return -1;
  }
  int fd = open(argv[2], O_RDWR | O_CREAT, 0666);
  write(fd, argv[1], strlen(argv[1]));
  write(fd, "\n", 1);
  // 此时文件已经到末尾了，需要移动读写位置
  lseek(fd, 0, SEEK_SET);
  char buf[256] = {0};
  int ret = read(fd, buf, sizeof(buf));
  write(STDOUT_FILENO, buf, ret);  // STDOUT_FILENO, STDIN_FILENO, STDERR_FILENO
  while (ret) {
    ret = read(fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, ret);
  }
  close(fd);
  return 0;
}
// 功能，终端输入内容写入指定文件，并且屏幕输出
````

#### 计算文件大小

````cpp
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
  int fd = open(argv[1], O_RDONLY);
  int ret = lseek(fd, 0, SEEK_END);
  printf("file size is: %d\n", ret);
  close(fd);
  return 0;
}
// 因为lseek返回值是从当前位置到开始的长度,所以可以计算文件大小
````

#### 扩展文件

````cpp
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
  int fd = open(argv[1], O_WRONLY | O_CREAT, 0666);
  // int ret = lseek(fd, 1024, SEEK_END);
  lseek(fd, 1024, SEEK_END);
  // 至少要写一次，才能创建指定大小文件
  write(fd, "\n", 1);
  close(fd);
  return 0;
}
// 此代码可以改变文件大小，即扩展文件
````

### 实现 cp 命令

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("./a.out filename1 filename2\n");
    return -1;
  }
  int fd1 = open(argv[1], O_RDONLY);
  int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0666);
  char buf[256];
  int ret = read(fd1, buf, sizeof(buf));
  write(fd2, buf, ret);
  while (ret) {
    ret = read(fd1, buf, sizeof(buf));
    write(fd2, buf, ret);
  }
  close(fd1);
  close(fd2);
  return 0;
}
// 复制的本质就是打开一个文件，读取所有内容，写入另一个文件
````

### stat函数

````bash
man 2 stat
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int stat(const char *pathname, struct stat *statbuf);
````

#### 参数介绍

+ **pathname** 文件名

+ **struct stat**

  + ````cpp
    struct stat {
      dev_t     st_dev;         /* ID of device containing file 文件设备编号*/
      ino_t     st_ino;         /* Inode number 索引节点*/
      mode_t    st_mode;        /* File type and mode 文件类型和存储权限*/
      nlink_t   st_nlink;       /* Number of hard links 硬链接数*/
      uid_t     st_uid;         /* User ID of owner 用户ID*/
      gid_t     st_gid;         /* Group ID of owner 组ID*/
      dev_t     st_rdev;        /* Device ID (if special file) 设备类型，若是设备，则为设备编号*/
      off_t     st_size;        /* Total size, in bytes 文件大小*/
      blksize_t st_blksize;     /* Block size for filesystem I/O 块大小*/
      blkcnt_t  st_blocks;      /* Number of 512B blocks allocated 块数*/
    
      /* Since Linux 2.6, the kernel supports nanosecond
         precision for the following timestamp fields.
         For the details before Linux 2.6, see NOTES. */
    
      struct timespec st_atim;  /* Time of last access 最后一次访问时间*/
      struct timespec st_mtim;  /* Time of last modification 最后一次修改时间*/
      struct timespec st_ctim;  /* Time of last status change 最后一次改变时间*/
    
    #define st_atime st_atim.tv_sec      /* Backward compatibility */
    #define st_mtime st_mtim.tv_sec
    #define st_ctime st_ctim.tv_sec
    };
    ````

#### 返回值

+ 成功返回0
+ 错误返回-1，设置 **errno** 

#### stat作用

+ 获取文件状态

#### 实现ls -l命令

```cpp
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  struct stat sb;
  stat(argv[1], &sb);
  char stmode[11] = {0};
  memset(stmode, '-', sizeof(stmode) - 1);
  if (S_ISREG(sb.st_mode)) {
    stmode[0] = '-';
  }
  if (S_ISDIR(sb.st_mode)) {
    stmode[0] = 'd';
  }
  if (S_ISCHR(sb.st_mode)) {
    stmode[0] = 'c';
  }
  if (S_ISBLK(sb.st_mode)) {
    stmode[0] = 'b';
  }
  if (S_ISFIFO(sb.st_mode)) {
    stmode[0] = 'p';
  }
  if (S_ISLNK(sb.st_mode)) {
    stmode[0] = 'l';
  }
  if (S_ISSOCK(sb.st_mode)) {
    stmode[0] = 's';
  }
  if (sb.st_mode & S_IRUSR) {
    stmode[1] = 'r';
  }
  if (sb.st_mode & S_IWUSR) {
    stmode[2] = 'w';
  }
  if (sb.st_mode & S_IXUSR) {
    stmode[3] = 'x';
  }
  if (sb.st_mode & S_IRGRP) {
    stmode[4] = 'r';
  }
  if (sb.st_mode & S_IWGRP) {
    stmode[5] = 'w';
  }
  if (sb.st_mode & S_IXGRP) {
    stmode[6] = 'x';
  }
  if (sb.st_mode & S_IROTH) {
    stmode[7] = 'r';
  }
  if (sb.st_mode & S_IWOTH) {
    stmode[8] = 'w';
  }
  if (sb.st_mode & S_IXOTH) {
    stmode[9] = 'x';
  }
  struct tm *filetm = localtime(&sb.st_atim.tv_sec);
  char timebuf[20] = {0};
  sprintf(timebuf, "%d月  %d %02d:%02d", filetm->tm_mon + 1, filetm->tm_mday,
          filetm->tm_hour, filetm->tm_min);
  printf("%s %ld %s %s %ld %s %s\n", stmode, sb.st_nlink,
         getpwuid(sb.st_uid)->pw_name, getgrgid(sb.st_gid)->gr_name, sb.st_size,
         timebuf, argv[1]);
  return 0;
}
// 可通过man inode 查看st_mode的更多信息
```

### access

```	bash
man 2 access
#include <unistd.h>
int access(const char *pathname, int mode);
```

#### 参数介绍

+ **pathname** 文件名
+ **mode** 模式
  + **R_OK** 可读？
  + **W_OR** 可写？
  + **X_OR** 可执行？
  + **F_OR** 存在？

#### 返回值

+ 如果文件存在或者有该权限返回0
+ 失败返回-1，设置 **errno**

#### access作用

+ 检查调用进程是否可以对指定的文件执行某种操作

#### 判断文件的各种权限

````cpp
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
````

### truncate

````bash
man 2 truncate
#include <unistd.h>
#include <sys/types.h>
int truncate(const char *path, off_t length)
````

#### 参数介绍

+ **path** 文件名
+ **length** 截取长度

#### 返回值

+ 成功返回0
+ 失败返回-1，设置 **errno**

#### truncate作用

+ 截取文件

#### truncate使用案例

````cpp
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
  truncate(argv[1], 1024);
  return 0;
}
// 执行完后文件大小变为1024，除此之外，如果设置的大小比原文件的小，会删除原文件内容
````

### link系列

#### link

````bash
man 2 link
#include <unistd.h>
int link(const char *oldpath, const char *newpath);
````

##### 参数介绍

+ **oldpath** 原文件
+ **newpath** 创建的硬链接文件

##### 返回值

+ 成功返回0
+ 失败返回-1，设置 **errno** 

##### link使用案例

````cpp
#include <fcntl.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  char *newhard = (char *)malloc(sizeof(argv[1]) * 2);
  strcpy(newhard, argv[1]);
  strcat(newhard, ".hard");
  puts(newhard);
  link(argv[1], newhard);
  return 0;
}
````

#### symlink

````bash
man 2 symlink
#include <unistd.h>
int symlink(const char *target, const char *linkpath);
````

##### 参数介绍

+ **target** 原文件
+ **linkpath** 软链接文件

##### 返回值

+ 成功返回0
+ 失败返回-1，设置 **errno**

##### symlink使用案例

````cpp
#include <fcntl.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  char *newsoft = (char *)malloc(sizeof(argv[1]) * 2);
  strcpy(newsoft, argv[1]);
  strcat(newsoft, ".soft");
  symlink(argv[1], newsoft);
  return 0;
}
````

#### readlink

````bash
man 2 readlink
#include <unistd.h>
ssize_t readlink(const char *pathname, char *buf, size_t bufsiz);
````

##### 参数介绍

+ **pathname** 文件名
+ **buf** 缓冲区
+ **bufsiz** 缓冲区大小

##### 返回值

+ 成功返回 **buf** 填充的大小
+ 失败返回-1，设置 **errno**

##### readlink使用案例

````cpp
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
  char buf[32] = {0};
  // 只能读取软链接
  readlink(argv[1], buf, sizeof(buf));
  printf("buf is %s\n", buf);
  return 0;
}
````

#### unlink

````bash
man 2 unlink
#include <unistd.h>
int unlink(const char *pathname);
````

##### 参数介绍

+ **pathname** 文件名

##### 返回值

+ 成功返回0
+ 失败返回-1，设置 **errno**

##### unlink使用案例

````cpp
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
  // 软硬都可以删除
  // 还可以删除文件
  unlink(argv[1]);
  return 0;
}
````

### chdir

````bash
man 2 chdir
#include <unistd.h>
int chdir(const char *path);
````

#### 参数介绍

+ **path** 路径

#### 返回值

+ 成功返回0
+ 失败返回-1，设置 **errno**

#### chdir 作用

+ 切换路径

### getcwd 得到路径

````bash
man 2 getcwd
#include <unistd.h>
char *getcwd(char *buf, size_t size);
````

#### 参数介绍

+ **buf** 缓冲区，传出路径
+ **size** 缓冲区大小

#### 返回值

+ 成功返回目录指针（目录）
+ 失败返回-1，设置 **errno**

### chdir 和 getcwd 使用案例

````cpp
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
  chdir(argv[1]);
  char buf[256];
  getcwd(buf, sizeof(buf));
  printf("buf is [%s]\n", buf);
  return 0;
}
````

### opendir 打开目录

````bash
man opendir
#include <sys/types.h>
#include <dirent.h>
DIR *opendir(const char *name);
````

#### 参数介绍

+ **name** 要打开的目录

#### 返回值

+ 成功返回一个目录流指针 **DIR** 
+ 失败返回 **NULL** 

### readdir 读取目录内容

````bash
man readdir
#include <dirent.h>
struct dirent *readdir(DIR *dirp);
````

#### 参数介绍

+ **dirp** 目录流指针

#### 返回值

+ 返回 **dirent structure** 

  + ````bash
    struct dirent {
                   ino_t          d_ino;       /* Inode number 索引节点*/
                   off_t          d_off;       /* Not an offset; see below */
                   unsigned short d_reclen;    /* Length of this record 长度*/
                   unsigned char  d_type;      /* Type of file; not supported
                                                  by all filesystem types 类型*/
                   char           d_name[256]; /* Null-terminated filename 名字*/
               };
    ````

### closedir 关闭目录

````bash
man closedir
#include <sys/types.h>
#include <dirent.h>
int closedir(DIR *dirp);
````

#### 参数介绍

+ **dirp** 目录流指针

#### 返回值

+ 成功返回0
+ 失败返回-1，设置 **errno** 

### 计算某个目录下有多少文件

+ 先用 **shell** 得出结果，与代码的验证，检验代码是否正确

  + ````shell
    find ./ -type f | wc -l
    ````

+ ````cpp
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
  // ./a.out ./
  ````

### dup

````bash
man 2 dup
#include <unistd.h>
int dup(int oldfd);// 复制文件描述符
int dup2(int oldfd, int newfd);// 新的文件描述符指向旧的文件描述符
````

#### 参数介绍

+ **oldfd** 旧的文件描述符
+ **newfd** 新的文件描述符

#### 返回值

+ 成功返回新的文件描述符
+ 失败返回-1，设置 **errno** 

#### dup 和 dup2 使用案例

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 复制文件描述符1
  int outfd = dup(1);
  int fd = open("world", O_WRONLY | O_CREAT, 0666);
  // 标准输出到fd文件描述符
  dup2(fd, 1);
  printf("Hello World!\n");
  close(fd);
  fflush(stdout);
  // 恢复，重新对应标准输出
  dup2(outfd, 1);
  printf("Hello World!\n");
  return 0;
}
// 作用，一个printf输出到文件，一个输出到屏幕
````

### 总结

才疏学浅，还请雅正！

把自己学习的过程记录下来，一是巩固自己所学，二是以后自己查看方便，三希望可以帮助到大家！

### 诗情画意

> <center>晚晴</center>
> <center>李商隐</center>
> <center>深居俯夹城，春去夏犹清。天意怜幽草，人间重晚晴。</center>
> <center>并添高阁迥，微注小窗明。越鸟巢干后，归飞体更轻。</center>