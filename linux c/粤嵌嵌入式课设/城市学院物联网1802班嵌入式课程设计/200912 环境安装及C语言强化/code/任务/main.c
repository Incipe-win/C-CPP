#include <stdio.h>
#include "read.h"	//所以要带上 read.h文件
	
int main(void)
{
	read_bmp("./1.bmp");	//因为函数定义在 read.c

	return 0;
}
