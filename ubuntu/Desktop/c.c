/*************************************************************************
	> File Name: c.c
	> Author: incipe
	> Mail: chaoh7461@gmail.com
	> Created Time: 2019年12月13日 星期五 14时39分25秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int pid1, pid2;
int main() {
  int fd[2];
  char OutPipe[100], InPipe[100];
  //建立管道：fd[1]为写入端，fd[0]为读出端。
  pipe(fd);
  //创建子进程1
  while ((pid1 = fork()) == -1)
    ;
  //子进程写管道消息
  if (pid1 == 0) {
    //给管道写入端上锁
    lockf(fd[1], 1, 0);
    sprintf(OutPipe, "\n Child process 1 is sending message!\n");
    //子进程通过管道发送消息
    write(fd[1], OutPipe, 50); //闪电nux下的写命令
    sleep(5);
    //给管道解锁
    lockf(fd[1], 0, 0);
    exit(0); //正常退出，并把参数返回父进程
  } else {
    //父进程创建第二个子进程
    while ((pid2 = fork()) == -1)
      ;
    //子进程2写管道信息
    if (pid2 == 0) {
      lockf(fd[1], 1, 0);
      sprintf(OutPipe, "\n Child process 2 is sending message!\n");
      write(fd[1], OutPipe, 50);
      // sleep()函数在windows系统和linux系统下是两个不同的函数，差别较大，但功能是相同的，都是将进程挂起一段时间。
      sleep(5);
      lockf(fd[1], 0, 0);
      exit(0);
    }
    //父进程接收管道消息
    else {
      // wait（0）父进程等待子进程结束并回收资源，用来防止子进程成为僵尸进程，0表示父进程不关心子进程的终止状态
      wait(0); //父进程阻塞自己，等待子进程中断或结束
      // sleep方法没有释放锁，而wait方法释放了锁，使得其他线程可以使用同步控制块或者方法。
      read(fd[0], InPipe, 50);
      printf("%s\n", InPipe);
      wait(0);
      read(fd[0], InPipe, 50);
      printf("%s\n", InPipe);
      exit(0);
    }
  }
  return 0;
}

