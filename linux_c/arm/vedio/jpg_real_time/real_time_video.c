#include <arpa/inet.h>
#include <fcntl.h>
#include <linux/input.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "api_v4l2.h"
#include "lcd.h"

FrameBuffer freambuf;

void *Jpg_Real_Time(void *arg) {
  lcd_open();
  linux_v4l2_device_init("/dev/video7");
  linux_v4l2_start_capturing();
  while (1) {
    linux_v4l2_get_fream(&freambuf);
    lcd_draw_jpg(80, 0, NULL, freambuf.buf, freambuf.length, 0);
  }
  linux_v4l2_stop_capturing();
  linux_v4l2_device_uinit();
  lcd_close();
}

int main(int argc, char *argv[]) {
  pthread_t tid;
  pthread_create(&tid, NULL, Jpg_Real_Time, NULL);
  pthread_join(tid, NULL);
  return 0;
}
