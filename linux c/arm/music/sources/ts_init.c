#include <fcntl.h>
#include <linux/input.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int ts = 0;
extern bool flag;

void get_touch(int *x, int *y) {
  int ret;
  struct input_event ev;  //输入事件结构体变量,用来保存读取的输入事件

  // 1) 打开触摸屏文件
  ts = open("/dev/input/event0", O_RDWR);
  if (-1 == ts) {
    perror("open input error");
    exit(-1);
  }

  // 2) 读取触摸屏事件
  while (1) {
    if (flag) {
      break;
    }
    ret = read(ts, &ev, sizeof(ev));  //读取输入事件保存到结构体ev中
    if (ret == sizeof(ev)) {
      if (ev.type == EV_ABS && ev.code == ABS_X) {
        *x = ev.value;  //此时的value是触摸点X轴的坐标
      }
      if (ev.type == EV_ABS && ev.code == ABS_Y) {
        *y = ev.value;  //此时的value是触摸点Y轴的坐标
      }
      if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0) {
        //手指从触摸屏 离开
        printf("(x = %d, y = %d)\n", *x, *y);
        break;
      }
    }
  }
}

void close_ts() { close(ts); }
