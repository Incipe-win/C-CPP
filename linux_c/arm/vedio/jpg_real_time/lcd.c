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

volatile int g_jpg_in_jpg_x = 400;
volatile int g_jpg_in_jpg_y = 240;

unsigned long file_size_get(const char *pfile_path) {
  unsigned long filesize = -1;
  struct stat statbuff;

  if (stat(pfile_path, &statbuff) < 0) {
    return filesize;
  } else {
    filesize = statbuff.st_size;
  }
  return filesize;
}

int lcd_open(void) {
  g_fb_fd = open("/dev/fb0", O_RDWR);
  if (g_fb_fd < 0) {
    printf("open lcd error\n");
    return -1;
  }
  g_pfb_memory = (int *)mmap(NULL, FB_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,
                             g_fb_fd, 0);
  return g_fb_fd;
}

void lcd_draw_point(unsigned int x, unsigned int y, unsigned int color) {
  *(g_pfb_memory + y * 800 + x) = color;
}

int lcd_draw_jpg(unsigned int x, unsigned int y, const char *pjpg_path,
                 char *pjpg_buf, unsigned int jpg_buf_size,
                 unsigned int jpg_half) {
  struct jpeg_decompress_struct cinfo;
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

  if (pjpg_path != NULL) {
    jpg_fd = open(pjpg_path, O_RDWR);
    if (jpg_fd == -1) {
      printf("open %s error\n", pjpg_path);
      return -1;
    }
    jpg_size = file_size_get(pjpg_path);
    pjpg = (char *)malloc(jpg_size);
    read(jpg_fd, pjpg, jpg_size);
  } else {
    jpg_size = jpg_buf_size;
    pjpg = pjpg_buf;
  }
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);
  jpeg_mem_src(&cinfo, pjpg, jpg_size);
  jpeg_read_header(&cinfo, TRUE);
  jpeg_start_decompress(&cinfo);
  if (jpg_half) {
    x_e = x_s + (cinfo.output_width / 2);
    y_e = y + (cinfo.output_height / 2);
    while (cinfo.output_scanline < cinfo.output_height) {
      pcolor_buf = g_color_buf;
      jpeg_read_scanlines(&cinfo, (unsigned char **)&pcolor_buf, 1);
      jpeg_read_scanlines(&cinfo, (unsigned char **)&pcolor_buf, 1);
      for (i = 0; i < (cinfo.output_width / 2); i++) {
        color = *(pcolor_buf + 2);
        color = color | *(pcolor_buf + 1) << 8;
        color = color | *(pcolor_buf) << 16;
        lcd_draw_point(x, y, color);
        pcolor_buf += 6;
        x++;
      }
      y++;
      x = x_s;
    }
  } else {
    x_e = x_s + cinfo.output_width;
    y_e = y + cinfo.output_height;
    while (cinfo.output_scanline < cinfo.output_height) {
      pcolor_buf = g_color_buf;
      jpeg_read_scanlines(&cinfo, (unsigned char **)&pcolor_buf, 1);

      for (i = 0; i < cinfo.output_width; i++) {
        color = *(pcolor_buf + 2);
        color = color | *(pcolor_buf + 1) << 8;
        color = color | *(pcolor_buf) << 16;
        lcd_draw_point(x, y, color);
        pcolor_buf += 3;
        x++;
      }
      y++;
      x = x_s;
    }
  }
  jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);

  if (pjpg_path != NULL) {
    close(jpg_fd);
    free(pjpg);
  }
  return 0;
}

void lcd_close(void) {
  munmap(g_pfb_memory, FB_SIZE);
  close(g_fb_fd);
}
