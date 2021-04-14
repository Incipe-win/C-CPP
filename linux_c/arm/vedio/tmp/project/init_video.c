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
#include "puzzle.h"

FrameBuffer freambuf;
int video_count = 1;
int video_fd = 0;

void *get_bmp(void *arg) {
  char video_name_buf[80];
  // lcd_open();
  // init video
  linux_v4l2_device_init("/dev/video7");
  // start video
  linux_v4l2_start_capturing();
  while (1) {
    if (video_count == 5) {
      break;
    }
    memset(video_name_buf, 0, sizeof(video_name_buf));
    // get video data
    linux_v4l2_get_fream(&freambuf);
    // show bmp in lcd
    lcd_draw_jpg(80, 0, NULL, freambuf.buf, freambuf.length, 0);
    // contact video bmp path
    sprintf(video_name_buf, "./video_jpg/%d.jpg", video_count);
    printf("take photos: %d\n", video_count++);
    sleep(1);
    // open video bmp and clear all content
    video_fd = open(video_name_buf, O_RDWR | O_CREAT | O_TRUNC);

    if (video_fd) {
      // write video bmp
      write(video_fd, freambuf.buf, freambuf.length);
      // clsoe video bmp
      close(video_fd);
    }
  }
  // stop video
  linux_v4l2_stop_capturing();
  // unregister video
  linux_v4l2_device_uinit();
  // lcd_close();
  // puzzle();
}
