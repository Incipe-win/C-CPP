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

void* get_bmp(void* arg) {
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
    sprintf(video_name_buf, "./video_bmp/%d.bmp", video_count);
    printf("take photos: %d\n", video_count++);
    sleep(1);
    // open video bmp and clear all content
    video_fd = open(video_name_buf, O_RDWR | O_CREAT | O_TRUNC);

    if (video_fd) {
      // write video bmp
      // write(video_fd, freambuf.buf, freambuf.length);
      // clsoe video bmp
      //分别为rgb数据，要保存的bmp文件名
      int size = 640 * 480 * 3 * sizeof(char);  // 每个像素点3个字节
      // 位图第一部分，文件信息
      BmpFileHead bfh;
      bfh.bfType = (unsigned short)0x4d42;  // bm
      bfh.bfSize = size + sizeof(BmpFileHead) + sizeof(BmpInfoHead);
      bfh.bfResvered1 = 0;  // reserved
      bfh.bfResvered2 = 0;  // reserved
      bfh.bfOffBits =
          sizeof(BmpFileHead) + sizeof(BmpInfoHead);  //真正的数据的位置
      printf("bmp_head == %ld\n", bfh.bfOffBits);
      // 位图第二部分，数据信息
      BmpInfoHead bih;
      bih.biSize = sizeof(BmpInfoHead);
      bih.biWidth = 640;
      bih.biHeight =
          -480;  // BMP图片从最后一个点开始扫描，显示时图片是倒着的，所以用-height，这样图片就正了
      bih.biPlanes = 1;  //为1，不用改
      bih.biBitCount = 24;
      bih.biCompression = 0;  //不压缩
      bih.biSizeImage = size;

      bih.biXPelsPerMeter = 0;  //像素每米

      bih.biYPelsPerMeter = 0;
      bih.biClrUsed = 0;       //已用过的颜色，为0,与bitcount相同
      bih.biClrImportant = 0;  //每个像素都重要

      // fwrite(&bfh, 8, 1, video_fd);
      write(video_fd, &bfh, sizeof(bfh));
      // fwrite(&bfh.bfResvered2, sizeof(bfh.bfResvered2), 1, video_fd);
      write(video_fd, &bfh.bfResvered2, sizeof(bfh.bfResvered2));
      // fwrite(&bfh.bfOffBits, sizeof(bfh.bfOffBits), 1, video_fd);
      write(video_fd, &bfh.bfOffBits, sizeof(bfh.bfOffBits));
      // fwrite(&bih, sizeof(BmpInfoHead), 1, video_fd);
      write(video_fd, &bih, sizeof(bih));
      // fwrite(pdata, size, 1, video_fd);
      write(video_fd, freambuf.buf, freambuf.length);
      // write_bmp(freambuf.buf, video_fd);
      close(video_fd);
    }
  }
  // stop video
  linux_v4l2_stop_capturing();
  // unregister video
  linux_v4l2_device_uinit();
  // lcd_close();
  // puzzle();
  return NULL;
}
