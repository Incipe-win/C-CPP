#include <errno.h>
#include "bmp.h"
#include "ts.h"

char * load_bmp(const char *bmpfile, struct image_info *minfo)
{
	int fd = open(bmpfile, O_RDONLY);
	if(fd == -1)
	{
		fprintf(stderr, "opening \"%s\" failed: %s\n",
					bmpfile, strerror(errno));
		exit(0);
	}

	// 获得文件大小，并分配内存
	struct stat fileinfo;
	fstat(fd, &fileinfo);

	int   rgb_size = fileinfo.st_size;
	char *rgb_buf  = calloc(1, rgb_size);

	// 读取BMP内容到内存中
	struct bitmap_header header;
	struct bitmap_info info;
	struct rgb_quad quad;
	read(fd, &header, sizeof(header));
	read(fd, &info, sizeof(info));
	if(info.compression != 0)
	{
		read(fd, &quad, sizeof(quad));
		fprintf(stderr, "read quad! \n");
	}
	read(fd, rgb_buf, rgb_size);

	minfo->width = info.width;
	minfo->height= info.height;
	minfo->pixel_size = info.bit_count/8;

	#ifdef DEBUG
	printf("width: %d\n", minfo->width);
	printf("height: %d\n", minfo->height);
	printf("pixel_size: %d\n", minfo->pixel_size);
	#endif

	close(fd);
	return rgb_buf;
}

void bmp2lcd(char *bmpfile, char *FB,
			 struct fb_var_screeninfo *vinfo,
			 int xoffset, int yoffset)
{
	xoffset = xoffset>(65*12+10) ? (65*10+10) : xoffset;

	struct image_info *minfo = calloc(1, sizeof(struct image_info));
	char *rgb_buf = load_bmp(bmpfile, minfo);
	char *tmp = rgb_buf;

	// 从最后一行开始显示BMP图像
	int pad = ((4-( minfo->width * minfo->pixel_size ) % 4)) % 4; // 0-3
	rgb_buf += (minfo->width * minfo->pixel_size + pad) * (minfo->height-1);	

	FB += (yoffset * vinfo->xres + xoffset) * 4;
	int lcd_w = vinfo->xres - xoffset;
	int lcd_h = vinfo->yres - yoffset;

	int x, y;
	for(x=0; x<lcd_h && x<minfo->height; x++)
	{
		for(y=0; y<lcd_w && y<minfo->width; y++)
		{
			unsigned long lcd_offset = (vinfo->xres*x + y) * 4;
			rgb_buf += minfo->pixel_size;

			memcpy(FB + lcd_offset + vinfo->red.offset/8,   rgb_buf + 2, 1);
			memcpy(FB + lcd_offset + vinfo->green.offset/8, rgb_buf + 1, 1);
			memcpy(FB + lcd_offset + vinfo->blue.offset/8,  rgb_buf + 0, 1);
		}

		rgb_buf += pad;
		rgb_buf -= (minfo->width * minfo->pixel_size + pad) * 2;
	}

	free(tmp);
}
