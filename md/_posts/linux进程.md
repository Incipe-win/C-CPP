## 一. 操作系统小知识

注：此笔记的重点不是讲操作系统，故操作系统知识比较粗浅，只是介绍。

### 1. 进程和程序 

+ 程序，是指编译好的二进制文件，在磁盘上，不占用系统资源。
+ 进程，是活跃的（动态的）的程序，占用系统资源，在内存中执行。进程是分配系统资源的基本单位。
+ 区别：
  + 程序是静态的，进程是动态的。
  + 程序一般保存在磁盘中，不占用系统资源，进程会占用系统资源。
  + 一个程序可以对应多个进程，一个进程可以执行一个或多个程序。
  + 进程具有并发性，而程序没有。
  + 程序没有生命周期，进程有生命周期（创建，执行，撤销等）。

### 2. 多道程序

+ 多道程序设计是指在内存同时放若干道程序，使它们在系统中并发执行，共享系统中的各种资源。当一道程序暂停执行时，CPU立即转去执行另一道程序。
+ 宏观并行，微观串行。

### 3. 进程状态转换

![进程状态转换图](https://imgkr.cn-bj.ufileos.com/79370c2a-d150-4882-bf94-ab5a6d93053c.jpg)

### 4. PCB(进程控制块)

+ PCB中记录了操作系统所需的，用于描述进程的当前情况以及控制进程运行的全部信息。
+ PCB主要内容：
  + 进程ID，系统中每一个程序都有唯一的一个id，在C/C++中用pid_t表示，也就是一个非负整数。
  + 进程状态，运行，就绪，阻塞，表示进程的运行情况。
  + CPU寄存器，进程切换，中断时需要保护和恢复的一些CPU寄存器。
+ 在linux下查看PCB信息：
  + 查找进程控制块信息 `sudo grep -rn "struct task_struct {" /usr/ `

## 二. Linux下进程学习

### 1. fork函数

创建一个新进程

````bash
man 2 fork
#include <sys/types.h>
#include <unistd.h>
pid_t fork(void);
````

#### 返回值

+ 失败返回-1
+ 成功，两次返回
  + 父进程返回子进程 id 
  + 子进程返回0

### 2. getpid函数

````bash
man 2 getpid
#include <sys/types.h>
#include <unistd.h>
pid_t getpid(void); // 获得当前进程的id
````

### 3. getppid函数

````bash
man 2 getppid
pid_t getppid(void); // 获得父进程的id
````

### 实例

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error");
    exit(1);
  } else if (pid == 0) {
    // 子进程
    printf("我是子进程, 进程id = %d, 父进程id = %d\n", getpid(), getppid());
    while (1) {
      sleep(1);
    }
  } else {
    // 父进程
    printf("子进程id = %d, 进程id = %d, 父进程id = %d\n", pid, getpid(),
           getppid());
    while (1) {
      sleep(1);
    }
  }
  return 0;
}
````

这里为什么要用设置两个死循环，稍后会讲。

通过`ps -aux`找到进程id，`kill PID`来杀死进程，这样进程资源由`init`进程释放。

### 关于fork小题目

> 执行如下代码时，系统中最多能产生的进程数为（）
>
> ````cpp
> int main() {
>     int i;
>     for (i = 0; i < 3; ++i) {
>         if (fork() > 0) {
>             break;
>         }
>     }
> }
> ````
>
> A. 8个			B. 5个			C.4个			D. 3个

通过代码得知，当fork的返回值大于0时，也就是父进程跳出for语句，感觉应该是选C. 4个

我们通过代码验算下，是否正确。

````cpp
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int i;
  for (i = 0; i < 3; ++i) {
    if (fork() > 0) {
      break;
    }
  }
  while (1) {
    sleep(1);
  }
  return 0;
}
````

我们让程序产生的所有进程都进入死循环，然后我们通过`ps -aux` 或者`ps -ajxf`

![](https://imgkr.cn-bj.ufileos.com/52200da3-d1f2-4c08-99a3-256bbae73061.png)

可以看到，的确只有四个进程。

`ps -aux`和`ps -ajxf`有点小区别。

`ps -ajxf`显示信息更全面，以目录树形式显示

+ 父进程id **ppid** 
+ 当前进程id **pid** 
+ 组进程id **pgid** 
+ 会话id **sid** 
+ 登录者终端机的位置(与终端无关用？显示) **TTY** 
  + 一般linux允许有7个TTY，可以用 `Ctrl + Alt + Fn` 来切换，n是要切换的终端号，比如 `Ctrl + Alt + F1` 切换到1号终端。
  + 还可以用 `chvt n` 来切换，比如 `chvt 1` 就是切换到1号终端。
+ 进程连接到的tty(终端)所在的前台进程组的ID **tpgid** 
+ 进程状态字段 **stat** 
  + D 不可中断的休眠，通常是I/O；
  + R 运行，正在运行或者在运行队列中等待；
  + S 休眠，在等待某个事件，信号，这是大写的S；
  + T 停止，进程接收到信息SIGSTOP，SIGSTP，SIGTIN，SIGTOU信号；
  + X 死掉的进程，不应该出现；
  + Z 僵尸进程；
  + <  高优先级；
  + N 低优先级；
  + L 有页面在内存中被锁存。用于实时或者自定义IO；
  + s 进程领导者，其有子进程，这是小写s；
  + l 多线程；
  + \+ 位于前台进程组；
  + 通过`man ps`查找 **STAT** 获取更详细的信息。
+ 用户表示号 **uid** 

![](https://imgkr.cn-bj.ufileos.com/5923248e-77ff-47a9-8a48-a768fbaee0b6.png)

### 4. 孤儿进程

孤儿进程指的是在其父进程执行完成或被终止后仍继续运行的一类进程。

比如我们前面写的实例代码，我们改成如下：

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error");
    exit(1);
  } else if (pid == 0) {
    // 子进程
    printf("我是子进程, 进程id = %d, 父进程id = %d\n", getpid(), getppid());
    while (1) {
      printf("我是子进程..., pid = %d, ppid = %d\n", getpid(), getppid());
      sleep(1);
    }
  } else {
    // 父进程
    printf("子进程id = %d, 进程id = %d, 父进程id = %d\n", pid, getpid(),
           getppid());
  }
  return 0;
}
````

![](https://imgkr.cn-bj.ufileos.com/b7ba31f6-0b02-4208-90d7-89f3330e412d.png)

我们可以看到，该子进程一直在运行，通过 **crtl + z** 或者 **ctrl + c** 是杀不死的。

用`ps -aux`看看情况。

![](https://imgkr.cn-bj.ufileos.com/628bb3c4-e036-46e7-b84f-130f047f4da6.png)

![](https://imgkr.cn-bj.ufileos.com/2fa6a33e-5c0a-47b0-bb10-7665f9cd4d6e.png)

看到他的父进程已经是 [systmd](https://zh.wikipedia.org/wiki/Systemd)了，所以用 **ctrl + z** 和 **ctrl + c** 是杀不死的，已经不归 **shell** 管了。

### 5. 僵尸进程

一个进程结束了，父进程没有释放其资源。

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
    exit(1);
  } else if (pid == 0) {
    printf("I am child process, pid = %d, ppid = %d\n", getpid(), getppid());
    sleep(2);
    printf("I am child, and i will die");
  } else {
    // 防止父进程先结束，产生孤儿进程。
    while (1) {
      printf("I am father process, pid = %d\n", getpid());
      sleep(1);
    }
  }
  // 杀死僵尸进程方法，把其父进程kill即可
  return 0;
}
````

运行程序，通过`ps -aux`看看什么情况

![](https://imgkr.cn-bj.ufileos.com/8426c499-cdce-4c54-a9d5-34fc5c5d1949.png)

![](https://imgkr.cn-bj.ufileos.com/f62a2474-c842-46bb-8939-51dc75d62378.png)

的确 **STAT** 标记为 **Z** ，此时产生了僵尸进程。

我们通过干掉父进程`kill 8433`

![](https://imgkr.cn-bj.ufileos.com/274323a5-f080-4385-9abf-54d0e418df9d.png)

看到僵尸进程已经没了，因为干掉父进程，僵尸进程由`init`释放了。

### 6. wait函数

僵尸进程危害还是挺大的，我们可以通过 **wait** 函数来释放子进程资源

````bash
man 2 wait
#include <sys/types.h>
#include <sys/wait.h>
pid_t wait(int *wstatus);
````

#### 参数

+ wstatus，这是一个传出参数，通过这个参数，我们可以判断子进程是怎么结束的。

#### 返回值

+ 成功，返回终止的子进程id；
+ 失败，返回-1。

#### 作用

+ 阻塞等待，如果子进程没结束，会陷入阻塞，直到子进程结束；
+ 回收子进程资源；
+ 查看子进程结束原因。

#### 子进程死亡原因

+ 正常死亡 **WIFEXITED** 
  + 如果 **WIFEXITED** 为真，使用 **WEXITSTATUS** 得到退出状态。
+ 非正常死亡 **WIFSIGNALED** 
  + 如果 **WIFSIGNALED** 为真，使用 **WTERMSIG** 得到信号。

#### 使用案例

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
    exit(1);
  } else if (pid == 0) {
    printf("I am child, will die, pid = %d, ppid = %d\n", getpid(), getppid());
    sleep(2);
    while (1) {
      printf("I am child, please die me\n");
      sleep(1);
    }
    // return 101;
    // exit(102);
  } else {
    printf("I am parent, wait child die!\n");
    int status;
    // 子进程没死，会陷入阻塞
    pid_t wpid = wait(&status);
    printf("wait ok, wpid = %d, pid = %d\n", wpid, pid);
    if (WIFEXITED(status)) {
      printf("child exit with %d\n", WEXITSTATUS(status));
    }
    if (WIFSIGNALED(status)) {
      printf("child exit by %d\n", WTERMSIG(status));
    }
  }
  return 0;
}
````

子进程是通过return 或 exit 结束的，返回对应的return 或 exit 后的数字。

通过kill杀死的，返回kill参数。

### 7. waitpid函数

````cpp
man 2 wait
#include <sys/types.h>
#include <sys/wait.h>
pid_t waitpid(pid_t pid, int *wstatus, int options);
````

#### 参数

+ pid
  + < -1 回收一组id；
  + -1 任意回收；
  + 0 回收和调用进程组id相同组内的子进程；
  + \> 0 回收指定进程。
+ wstatus同wait
+ options
  + 0，与wait函数相同，产生阻塞；
  + WNOHANG， 如果当前没有子进程退出，会立刻返回。

#### 返回值

+ 如果设置了 **WNOHANG** ，那么如果没有子进程退出，返回0
  + 如果有子进程退出，返回退出子进程的pid。
+ 失败返回-1，没有子进程

#### 使用案例

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork err");
    exit(1);
  } else if (pid == 0) {
    printf("I am child process, pid = %d, ppid = %d\n", getpid(), getppid());
    sleep(2);
  } else {
    printf("I am pather process, pid = %d, ppid = %d\n", getpid(), getppid());
    // 参数WNOHANG,不等待子进程结束，也就是不陷入阻塞态
    int ret;
    while ((ret = waitpid(-1, NULL, WNOHANG)) == 0) {
      sleep(1);
    }
    printf("ret = %d\n", ret);
    // 防止产生孤儿进程
    while (1) {
      sleep(1);
    }
  }
  return 0;
}
````

### 8. 多个子进程回收

 创建了几个子进程，就用几次循环，用wait释放资源即可。

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int n = 5;
  int i;
  pid_t pid;
  for (i = 0; i < n; ++i) {
    pid = fork();
    if (pid == 0) {
      printf("I am a child process, pid = %d, ppid = %d\n", getpid(),
             getppid());
      break;
    }
  }
  sleep(i);
  if (i == 5) {
    printf("I am a parent process, pid = %d\n", getpid());
    for (i = 0; i < n; ++i) {
      pid_t wpid = wait(NULL);
      printf("wpid = %d\n", wpid);
    }
    // 防止产生孤儿进程
    while (1) {
      sleep(1);
    }
  }
  return 0;
}
````

​    使用waitpid同理

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int n = 5;
  int i;
  pid_t pid;
  for (i = 0; i < n; ++i) {
    pid = fork();
    if (pid < 0) {
      perror("fork err");
      exit(1);
    }
    if (pid == 0) {
      printf("I am child process, pid = %d, ppid = %d\n", getpid(), getppid());
      break;
    }
  }
  sleep(i);
  if (i == 5) {
    printf("I am parent process, pid = %d\n", getpid());
    while (1) {
      pid_t wpid = waitpid(-1, NULL, WNOHANG);
      if (wpid == -1) {
        break;
      } else if (wpid > 0) {
        printf("wpid = %d\n", wpid);
      }
    }
    // 防止产生孤儿进程
    while (1) {
      sleep(1);
    }
  }
  return 0;
}
````

### 9. 补充Linux的API函数

#### execl函数族

````bash
man execl
#include <unistd.h>
int execl(const char *pathname, const char *arg, ...
                       /* (char  *) NULL */);
int execlp(const char *file, const char *arg, ...
                       /* (char  *) NULL */);
````

只抽取了两个比较常用的。

execlp跟execl的区别：

+ execl要使用PATH环境变量，而execlp不要使用完整加路径。

##### 参数

+ pathname，命令的PATH
+ file，命令
+ arg，参数，可以有多个，最后一个为NULL，表示参数已经添加完。

#### 返回值

+ 只有发生错误时才返回，设置error。

##### 功能

+ 在调用进程内部执行一个可执行文件。可执行文件既可以是二进制文件，也可以是任何Linux下可执行的脚本文件。

##### 使用案例

````cpp
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  execlp("ls", "ls", "-lrt", NULL);
  execl("/bin/ls", "ls", "-lrt", NULL);
  perror("error fault");
  return 0;
}
````

## 三. 总结

学习是不断积累，写笔记能让巩固自己所学知识，也希望可以帮助到大家。

我们看到每次我们都要让父进程进入死循环，目的是为了防止父进程先结束，产生了孤儿进程，难道就没有其它容易的解决办法吗？

关注我，下次带你解决这个问题。

## 诗情画意

> <center>虞美人·听雨</center>
> <center>蒋捷</center>
> <center>少年听雨歌楼上，红烛昏罗帐。壮年听雨客舟中，江阔云低，断雁叫西风。</center>
> <center>而今听雨僧庐下，鬓已星星也。悲欢离合总无情，一任阶前，点滴到天明。</center>
> <center></center>

