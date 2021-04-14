#include <fcntl.h>  //open write read lseek close
#include <stdio.h>  //printf scanf
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "api_v4l2.h"
#include "jpeglib.h"
#include "lcd.h"

static char g_color_buf[FB_SIZE] = {0};

static int g_fb_fd;
static int *g_pfb_memory;

// get filesize
unsigned long file_size_get(const char *pfile_path) {
  unsigned long filesize = -1;
  struct stat statbuff;
  // stat get file status, and get file size
  if (stat(pfile_path, &statbuff) < 0) {
    return filesize;
  } else {
    filesize = statbuff.st_size;
  }
  return filesize;
}

// open lcd
int lcd_open(void) {
  g_fb_fd = open("/dev/fb0", O_RDWR);
  if (g_fb_fd < 0) {
    printf("open lcd error\n");
    return -1;
  }
  // mmap malloc share area
  g_pfb_memory = (int *)mmap(NULL, FB_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,
                             g_fb_fd, 0);

  return g_fb_fd;
}

// draw rgb in lcd
void lcd_draw_point(unsigned int x, unsigned int y, unsigned int color) {
  *(g_pfb_memory + y * 800 + x) = color;
}

int lcd_draw_jpg(unsigned int x, unsigned int y, const char *pjpg_path,
                 char *pjpg_buf, unsigned int jpg_buf_size,
                 unsigned int jpg_half) {
  // 定义解码对象，错误处理对象
  struct jpeg_decompress_struct cinfo;
  cinfo.out_color_space = JCS_RGB;
  struct jpeg_error_mgr jerr;
  char *pcolor_buf = g_color_buf;
  char *pjpg;
  unsigned int i = 0;
  unsigned int color = 0;
  unsigned int count = 0;
  unsigned int x_s = x;
  unsigned int x_e;
  unsigned int y_e;
  int jpg_fd;
  unsigned int jpg_size;
  unsigned int jpg_width;
  unsigned int jpg_height;
  jpg_size = jpg_buf_size;
  pjpg = pjpg_buf;
  // 注册出错处理
  cinfo.err = jpeg_std_error(&jerr);
  // 创建解码
  jpeg_create_decompress(&cinfo);
  // 直接解码内存数据
  jpeg_mem_src(&cinfo, pjpg, jpg_size);
  // 读文件头
  jpeg_read_header(&cinfo, TRUE);
  // 开始解码
  jpeg_start_decompress(&cinfo);
  x_e = x_s + cinfo.output_width;
  y_e = y + cinfo.output_height;
  // 读解码数据
  while (cinfo.output_scanline < cinfo.output_height) {
    pcolor_buf = g_color_buf;
    // 读取jpg一行rgb
    jpeg_read_scanlines(&cinfo, (unsigned char **)&pcolor_buf, 1);
    for (i = 0; i < cinfo.output_width; i++) {
      // 计算rgb值
      color = *(pcolor_buf + 2);
      color = color | *(pcolor_buf + 1) << 8;
      color = color | *(pcolor_buf) << 16;
      // 显示像素点
      lcd_draw_point(x, y, color);
      pcolor_buf += 3;
      x++;
    }
    // 读下一行
    y++;
    x = x_s;
  }
  // 解码完成
  jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);
  if (pjpg_path != NULL) {
    // 关闭jpg文件
    close(jpg_fd);
    // 释放内存空间
    free(pjpg);
  }
  return 0;
}

// close lcd
void lcd_close(void) {
  // 释放共享内存
  munmap(g_pfb_memory, FB_SIZE);
  // 关闭文件描述符
  close(g_fb_fd);
}
