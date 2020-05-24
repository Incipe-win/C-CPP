### 一. Linux进程间通信

#### Ⅰ. 管道函数

管道是有大小的，通过`ulimit -a`查看管道大小

![管道](https://imgkr.cn-bj.ufileos.com/5b9f0c3d-2ed4-470f-9400-6e727c54dfb1.png)

````bash
man 2 pipe
#include <unistd.h>
int pipe(int pipefd[2]);
````

+ 参数
  + 文件描述符。

+ 读管道
  + 写端全部关闭 ，read读到0，相当于读到文件末尾
  + 写端没有关闭
    + 有数据，read读到数据；
    + 没数据，read阻塞，fcntl函数可以设置非阻塞。
+ 写管道
  + 读端全部关闭，产生一个SIGPIPE信号，程序异常终止
  + 读端未全部关闭
    + 管道已满，write阻塞；
    + 管道未满， write正常写入。
+ 管道优点
  + 简单
+ 缺点
  + 只能有血缘关系的进程通信；
  + 父子进程只能单方向通信，如果需要双向通信，需要创建多根管道。

##### 实践

+ 简单应用

````cpp
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd[2];
  pipe(fd);
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error:");
  } else if (pid == 0) {
    printf("I am a child fork, pid = %d, ppid = %d\n", getpid(), getppid());
    write(fd[1], "hello", 5);
  } else {
    printf("I am a parent fork, pid = %d\n", getpid());
    char buf[12] = {0};
    int ret = read(fd[0], buf, sizeof(buf));
    if (ret > 0) {
      write(STDOUT_FILENO, buf, ret);
    }
  }
  return 0;
}
````

+ 实现Linux的shell的管道通信，例如`ps -aux | grep zsh`

````cpp
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd[2];
  pipe(fd);
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
  } else if (pid == 0) {
    // 子进程负责把ps -aux查询到的内容写到管道里去
    printf("I am a child process, pid = %d, ppid = %d\n", getpid(), getppid());
    // 子进程只负责写，不要读，所以要关闭读端
    close(fd[0]);
    // 把输出到屏幕的内容重定向到写端
    dup2(fd[1], STDOUT_FILENO);
    execlp("ps", "ps", "-aux", NULL);
  } else {
    // 父进程负责把grep zsh得到的内容输出到屏幕
    printf("I am a parent process, pid = %d\n", getpid());
    // 父进程只负责读数据
    close(fd[1]);
    // 输入重定向到读管道
    dup2(fd[0], STDIN_FILENO);
    execlp("grep", "grep", "zsh", NULL);
  }
  return 0;
}
````

+ 两个子进程通信

````cpp
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main() {
  int fd[2];
  pid_t pid;
  if (pipe(fd) < 0) {
    perror("pipe: ");
    exit(1);
  }
  if ((pid = fork()) < 0) {
    perror("fork: ");
    exit(1);
  } else if (pid == 0) {
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    execlp("ps", "ps", "-aux", NULL);
  }
  if ((pid = fork()) < 0) {
    perror("fork: ");
    exit(1);
  } else if (pid == 0) {
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    execlp("grep", "grep", "zsh", NULL);
  } else {
    close(fd[0]);
    close(fd[1]);
    for (int i = 0; i < 2; ++i) {
      pid_t wpid = wait(NULL);
      printf("wpid = %d\n", wpid);
    }
  }
  return 0;
}
````

#### Ⅱ. 有名管道

FIFO有名管道，可以实现无血缘关系进程通信。

+ 创建一个管道的伪文件
  + `mkfifo + 文件名` 命令创建
  + 也可以用函数`int mkfifo(const char *pathname, mod_t mode);`

+ 原理
  + 内核会针对FIFO文件开辟一个缓冲区，操作FIFO文件，可以操作缓冲区，实现进程间通信，实际上就是文件读写操作。
  + 用open打开FIFO文件的时候，read端会阻塞等待write端open，write端同理，open也会阻塞等待另外一端read打开。

##### 实践

+ 有名管道实现两个进程的通信

````cpp
// write function
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // 确保当前路径有fifo有名管道文件
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  printf("open begin...\n");
  int fd = open(argv[1], O_WRONLY);
  printf("open end...\n");
  char buf[256];
  int num = 1;
  while (1) {
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "fifo%04d", num++);
    write(fd, buf, sizeof(buf));
    sleep(1);
    if (num == 100) {
      break;
    }
  }
  close(fd);
  return 0;
}
````

````cpp
// read function
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  printf("open begin...\n");
  int fd = open(argv[1], O_RDONLY);
  printf("open end...\n");
  char buf[256];
  while (1) {
    int ret = read(fd, buf, sizeof(buf));
    printf("read: %s\n", buf);
    if (ret == 0) {
      break;
    }
  }
  close(fd);
  return 0;
}
````

#### Ⅲ. mmap共享映射区

Linux提供了内存映射函数mmap，它把文件内容映射到一段内存上(准确说是虚拟内存上)，通过对这段内存的读取和修改, 实现对文件的读取和修改，mmap()系统调用使得进程之间可以通过映射一个普通的文件实现共享内存。

普通文件映射到进程地址空间后，进程可以向访问内存的方式对文件进行访问，不需要其他系统调用(read,write)去操作。

![mmap](https://imgkr.cn-bj.ufileos.com/3971d173-7e9d-42ec-8a08-020e3b9812cd.png)

````bash
man 2 mmap
#include <sys/mman.h>
// 创建映射区
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
// 释放映射区
int munmap(void *addr, size_t length);

````

+ 参数
  + addr，一般传NULL
  + length，映射区长度
  + prot
    + PROT_READ，可读
    + PROT_WRITE ，可写
  + flags
    + MAP_SHARED ，共享的， 对内存的修改会影响到源文件，实现通信选共享
    + MAP_PRIVATE，私有的
  + fd
    + 文件描述符，open打开一个文件
  + offset	
    + 偏移量

+ 返回值
  + 成功，返回可用的内存首地址
  + 失败， 返回MAP_FAILED

##### 实践

+ 简单使用

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./a.out filename\n");
    return -1;
  }
  int fd = open(argv[1], O_RDWR);
  char *mem = (char *)mmap(NULL, 8, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (mem == MAP_FAILED) {
    perror("mmap error:");
    return -1;
  }
  strcpy(mem, "hello");
  // 最好哟个mscpy
  if (munmap(mem, 8) < 0) {
    perror("munmap error:");
  }
  close(fd);
  return 0;
}
````

+ 父子进程通信

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int fd = open("./mem.txt", O_RDWR);
  int *mem = (int *)mmap(NULL, 8, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (mem == MAP_FAILED) {
    perror("mmap error:");
    return -1;
  }
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error:");
    return -1;
  } else if (pid == 0) {
    *mem = 100;
    printf("child, *mem = %d\n", *mem);
    sleep(3);
    printf("child, *mem = %d\n", *mem);
  } else {
    sleep(1);
    printf("parent, *mem = %d\n", *mem);
    *mem = 1001;
    printf("parent, *mem = %d\n", *mem);
    wait(NULL);
  }
  munmap(mem, 8);
  close(fd);
  return 0;
}
````

+ 匿名映射

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int *mem = (int *)mmap(NULL, 8, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON,
                         -1, 0);
  if (mem == MAP_FAILED) {
    perror("mmap error:");
    return -1;
  }
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error:");
    return -1;
  } else if (pid == 0) {
    *mem = 100;
    printf("child, *mem = %d\n", *mem);
    sleep(3);
    printf("child, *mem = %d\n", *mem);
  } else {
    sleep(1);
    printf("parent, *mem = %d\n", *mem);
    *mem = 1001;
    printf("parent, *mem = %d\n", *mem);
    wait(NULL);
  }
  munmap(mem, 8);
  return 0;
}
// 匿名映射，只需要再创建时加上关键字MAP_ANON即可
````

### 二. 总结

学习了Linux进程通信，多个进程可以进行“信息交流”，实现了一个多进程复制。

多进程复制原理(步骤)：

1. 求出要被复制的文件的大小，分成n份，$part = flen\ /\ n$ , 每个进程完成一部分，除不尽的部分$remain = flen\ \%\ n$
2. 最后一个进程复制时把剩下的remain也复制了。

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("./a.out strfile dstfile\n");
    return -1;
  }
  // 5进程
  int n = 5;
  // 打开，要被复制的文件
  int fd1 = open(argv[1], O_RDONLY);
  if (fd1 < 0) {
    perror("open_src:");
    exit(1);
  }
  // 打开，要复制的文件
  int fd2 = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0666);
  if (fd2 < 0) {
    perror("open_dst:");
    exit(2);
  }
  // 计算文件大小
  int flen = lseek(fd1, 0, SEEK_END);
  printf("flen = %d\n", flen);
  // 扩展文件大小
  ftruncate(fd2, flen);
  char *src = (char *)mmap(NULL, flen, PROT_READ, MAP_SHARED, fd1, 0);
  if (src == MAP_FAILED) {
    printf("mmap_src error:");
    exit(3);
  }
  close(fd1);
  char *dst =
      (char *)mmap(NULL, flen, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
  if (dst == MAP_FAILED) {
    perror("mmap_dst error:");
    exit(4);
  }
  close(fd2);
  // 分成part部分，除不尽的留给最后一个进程
  int part = flen / n;
  int remain = flen % n;
  printf("part = %d, remain = %d\n", part, remain);

  int i;
  pid_t pid;
  for (i = 0; i < n; ++i) {
    // 创建n个进程
    printf("%dth process\n", i);
    if ((pid = fork()) == 0) {
      break;
    }
  }
  if (n == i) {
    // 父进程，需要释放子进程资源
    for (int j = 0; j < n; ++j) {
      wait(NULL);
    }
  } else if (i == (n - 1)) {
    printf("i = %d\n", i);
    // 最后一个子进程,要把除不尽的也拷贝了。
    memcpy(dst + i * part, src + i * part, part + remain);
  } else if (i == 0) {
    printf("i = %d\n", i);
    // 第一个子进程，从最初的位置开始拷贝
    memcpy(dst, src, part);
  } else {
    printf("i = %d\n", i);
    // 另外的子进程，拷贝
    memcpy(dst + i * part, src + i * part, part);
  }
  // 释放mmap
  munmap(src, flen);
  munmap(dst, flen);
  return 0;
}
````

### 诗情画意

> <center>丑奴儿</center>
> <center>辛弃疾</center>
> <center>少年不识愁滋味，爱上层楼。爱上层楼，为赋新词强说愁。</center>
> <center>而今识尽愁滋味，欲说还休。欲说还休，却道天凉好个秋。</center>