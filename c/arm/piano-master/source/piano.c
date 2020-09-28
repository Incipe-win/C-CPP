#include "ts.h"
#include "bmp.h"
#include <pthread.h>
#include <unistd.h>
#include "audio.h"
#include "scorenum.h"
#define ON 1
#define OFF 0
char keyON[][50] = {KEY1ON, KEY2ON, KEY3ON, KEY4ON, KEY5ON, KEY6ON, KEY7ON};
char keyOFF[][50] = {KEY1OFF, KEY2OFF, KEY3OFF, KEY4OFF, KEY5OFF, KEY6OFF, KEY7OFF};
int white[2][12], black[2][11], line[12], key[7]; //1.按键范围，2.按键是否被按
char *FB;
int lcd;
struct fb_var_screeninfo vinfo;
pthread_t tid;
pthread_t touchid;				 //触摸多线程
pthread_t gameid;				 //游戏多线程
pthread_t playid;				 //游戏内单个键多线程
struct coordinate coor, oldcoor; //按键x，y
bool released = false;

char *init_lcd(struct fb_var_screeninfo *vinfo)
{
	lcd = open("/dev/fb0", O_RDWR);

	bzero(vinfo, sizeof(struct fb_var_screeninfo));
	ioctl(lcd, FBIOGET_VSCREENINFO, vinfo);

	FB = mmap(NULL, vinfo->xres * vinfo->yres * 4,
			  PROT_READ | PROT_WRITE,
			  MAP_SHARED, lcd, 0);
	return FB;
}

void init_frame()
{

	// 显示背景
	bmp2lcd(BACKGROUND, FB, &vinfo, 0, 0);
	// 显示标题栏
	bmp2lcd(BAR, FB, &vinfo, 0, 0);
	// 显示琴键
	int i, j;
	for (i = 0; i < 12; i++)
	{
		line[i] = 65 * i + 42;
		bmp2lcd(GAMELINE, FB, &vinfo, line[i], 0);

		white[0][i] = 65 * i + 10;
		white[1][i] = OFF;
		bmp2lcd(KEYOFF, FB, &vinfo, white[0][i], 47);
		if (i > 0)
		{
			j = i - 1;
			if (j == 2 || j == 5 || j == 9)
			{
				continue;
			}
			black[0][j] = 65 * j + 53;
			black[1][j] = OFF;
			bmp2lcd(KEYBLACKOFF, FB, &vinfo, black[0][i - 1], 47);
		}
	}
	// 显示音乐按键
	// bmp2lcd(KEY1, FB, &vinfo, 10, 430);
	// bmp2lcd(KEY2, FB, &vinfo, 100, 430);
	// bmp2lcd(KEY3, FB, &vinfo, 190, 430);
	// bmp2lcd(KEY4, FB, &vinfo, 280, 430);
	int len = sizeof(keyOFF) / sizeof(keyOFF[0]);
	printf("keynum==%d\n", len);
	for (i = 0; i < len; i++)
	{
		key[i] = 10 + i * 85;
		bmp2lcd(keyOFF[i], FB, &vinfo, key[i], 430);
	}
	// 显示停止按键
	bmp2lcd(KEYSTOP, FB, &vinfo, 720, 430);
}
void delay(float time)
{
	usleep(time * 1000);
}

// 点击了在琴键之外区域
bool out_of_range(struct coordinate *coor, struct coordinate *oldcoor)
{
	if (oldcoor->x == coor->x && oldcoor->y == coor->y && released == false)
	{
		// coor->x = 0;
		// coor->y = 0;
		return true;
	}
	if (coor->x < 10 || coor->x > 790)
	{
		return true;
	}
	return false;
}

bool in_of_range(int x1, int x2, int y1, int y2)
{
	if (coor.y > y1 && coor.y < y2 && coor.x > x1 && coor.x < x2)
	{
		return true;
	}
	return false;
}
void usage(const char *prog)
{
	printf("\nwelcome you you you\nUsage: %s volume[0-3]\n", prog);
}
//白色单个按键处理
void key_white(bool key, int pos)
{
	printf("key is %d\n pos is %d \n", key, pos);
	if (pos == 0 || pos == 3 || pos == 6 || pos == 10)
	{
		if (key)
		{
			bmp2lcd(KEYON, FB, &vinfo, white[0][pos], 47);
		}
		else
		{
			bmp2lcd(KEYOFF, FB, &vinfo, white[0][pos], 47);
		}
		bmp2lcd(KEYBLACKOFF, FB, &vinfo, black[0][pos], 47);
	}
	else if (pos == 2 || pos == 5 || pos == 9 || pos == 11)
	{
		if (key)
		{
			bmp2lcd(KEYON, FB, &vinfo, white[0][pos], 47);
		}
		else
		{
			bmp2lcd(KEYOFF, FB, &vinfo, white[0][pos], 47);
		}
		bmp2lcd(KEYBLACKOFF, FB, &vinfo, black[0][pos - 1], 47);
	}
	else
	{
		if (key)
		{
			bmp2lcd(KEYONC, FB, &vinfo, white[0][pos], 47);
		}
		else
		{
			bmp2lcd(KEYOFFC, FB, &vinfo, white[0][pos], 47);
		}
		bmp2lcd(KEYBLACKOFF, FB, &vinfo, black[0][pos], 47);
	}
}

//选择黑或白键
void key_white_black(bool keyon, bool is_white, int pos)
{
	printf("keyon is %d\n is_white is %d\n pos is %d \n", keyon, is_white, pos);

	if (is_white)
	{
		key_white(keyon, pos);
	}
	else
	{
		if (keyon)
		{
			if (pos == 2 || pos == 5 || pos == 9)
			{
				return;
			}
			bmp2lcd(KEYBLACKON, FB, &vinfo, black[0][pos], 47);
		}
		else
		{
			if (pos == 2 || pos == 5 || pos == 9)
			{
				return;
			}
			bmp2lcd(KEYBLACKOFF, FB, &vinfo, black[0][pos], 47);
		}
	}
}

//黑白键处理
bool piano_change(bool is_white, int new_pos, int old_pos, bool touch)
{
	int num = 0;
	printf("is_white is %d\tnew_pos is %d\told_pos is %d \treleased is %d\t touch is %d\n", is_white, new_pos, old_pos, released, touch);
	if (released)
	{
		key_white_black(false, is_white, new_pos);
		touch = true;
		released = false;
		return touch;
	}
	if (new_pos != old_pos || touch)
	{
		//更新琴键状态
		key_white_black(true, is_white, new_pos);
		if (!touch)
			key_white_black(false, is_white, old_pos);
		else
			touch = false;
		// 使用madplay播放琴音
		if (is_white)
		{
			pthread_create(&tid, NULL, play_note, (void *)(new_pos));
		}
		else
		{
			if (new_pos == 2 || new_pos == 5 || new_pos == 9)
			{
				return touch;
			}
			if (new_pos > 2)
				num++;
			if (new_pos > 5)
				num++;
			if (new_pos > 9)
				num++;
			printf("playnotes is %d\n", new_pos - num + 12);
			pthread_create(&tid, NULL, play_note, (void *)(new_pos - num + 20));
		}
	}
	return touch;
}

//歌曲播放
void music_score(int m[])
{
	int i;
	int len = m[0]; //歌曲长度
	printf("len is %d\n", len);

	for (i = 1; i < len; i += 2)
	{ //歌曲结尾退出

		if (m[i] == 0)
		{
			break;
		}
		//歌曲分段
		if (m[i] <= 0)
		{
			delay(m[i + 1]);
			continue;
		}
		printf("music is %d\n", m[i]);
		key_white(true, m[i] - 1);
		pthread_create(&tid, NULL, play_note, (void *)(m[i] - 1));

		delay(m[i + 1] * 0.9);
		key_white(false, m[i] - 1);
		delay(m[i + 1] * 0.1);
		if (in_of_range(720, 800, 430, 480))
		{
			printf("exit\n");
			break;
		}
	}
}
void *get_touch_xy(void *n)
{
	while (1)
	{
		// 等待手指触碰琴键
		wait4touch(&coor, &released);
	}
}

int main(int argc, char **argv)
{
usage(argv[0]);
if (argc == 2)
{
	switch (atoi(argv[1]))
	{
	case 0:
		vol = -105;
		break;
	case 1:
		vol = -45;
		break;
	case 2:
		vol = -15;
		break;
	case 3:
		vol = 10;
		break;
	}
}
else
{
	vol = -45;
}
// 准备LCD
FB = init_lcd(&vinfo);
bzero(FB, vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8);
//初始化界面
init_frame();
// 准备触摸屏
Init_Ts();
//设置线程分离属性
// pthread_attr_init(NULL);
// pthread_attr_setdetachstate(NULL, PTHREAD_CREATE_DETACHED);
int wnew_pos = 0, wold_pos = 0, bnew_pos = 0, bold_pos = 0;
bool w_touch = true, b_touch = true;
int len;
bool use_touch = false;
pthread_create(&touchid, NULL, get_touch_xy, NULL);
while (1)
{
	delay(10); //防止太快导致coor没写入就读取
	// printf("x=%d  y=%d \n", coor.x, coor.y);
	if (out_of_range(&coor, &oldcoor))
		continue;
	oldcoor.x = coor.x;
	oldcoor.y = coor.y;
	//黑色键部分
	if (coor.y > 47 && coor.y < 47)
	{
		bold_pos = bnew_pos;
		bnew_pos = (coor.x - 50) / 65;
		printf("black x=%d  y=%d wnew_pos=%d\n", coor.x, coor.y, bnew_pos);
		if (bnew_pos > 10)
		{
			continue;
		}

		b_touch = piano_change(false, bnew_pos, bold_pos, b_touch);
		use_touch = true;
		continue;
	}
	//白色键部分
	if (coor.y > 47 && coor.y < 280)
	{
		wold_pos = wnew_pos;
		wnew_pos = (coor.x - 10) / 65;
		printf("white x=%d  y=%d wnew_pos=%d\n", coor.x, coor.y, wnew_pos);
		if (wnew_pos > 11)
		{
			wnew_pos = 11;
		}

		w_touch = piano_change(true, wnew_pos, wold_pos, w_touch);
		use_touch = true;
		continue;
	}
	//歌曲部分
	if (coor.y > 430 && coor.y < 480)
	{
		printf("music x=%d  y=%d \n", coor.x, coor.y);

		//歌曲选择
		int i;
		for (i = 0; i < 7; i++)
		{
			if (coor.x > 10 + i * 90 && coor.x < 90 + i * 90)
			{
				len = sizeof(musicnum[i]) / sizeof(musicnum[i][0]);
				musicnum[i][0] = len;
				bmp2lcd(keyON[i], FB, &vinfo, key[i], 430);
				music_score(musicnum[i]);
				bmp2lcd(keyOFF[i], FB, &vinfo, key[i], 430);
				break;
			}
		}
		coor.x = 0;
		coor.y = 0;
		released = false;
		continue;
	}
	//黑白键超出范围重置按键
	if (coor.y > 0 && coor.y < 47 && use_touch)
		bmp2lcd(KEYBLACKOFF, FB, &vinfo, black[0][bold_pos], 47);
	if (coor.y > 320 && coor.y < 430 && use_touch)
		key_white(false, wold_pos);
	use_touch = false;

	if (in_of_range(0, 50, 0, 50))  
	{
		printf("exit piano\n");
		break;
	}
}
	//结束和卸载程序
	UnInit_Ts();
	//撤销映射
	munmap(FB,			   //映射后的地址，通过mmap返回的值
		   800 * 480 * 4); //映射的大小
	close(lcd);
	pthread_exit(NULL);
	pthread_join(tid, NULL);
	pthread_join(gameid, NULL);
	pthread_join(playid, NULL);
	exit(0);
	return 0;
}
