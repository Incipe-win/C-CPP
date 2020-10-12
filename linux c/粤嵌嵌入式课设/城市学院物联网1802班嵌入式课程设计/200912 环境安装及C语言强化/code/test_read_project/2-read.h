/*
	.h文件中通用格式是用 3个#语句(预编译)来防止头文件
	重复包含
*/

#ifndef		__2_READ_H__
#define 	__2_READ_H__

//声明
/* 
	read_file 从指定的文件中读取数据
		@file: 指定文件名
	返回值:
		成功 返回0
		失败 返回-1
*///声明在同名的.c文件中,定义了 下面这个函数
int read_file(char * file); 


#endif


