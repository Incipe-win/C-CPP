/*
 * > FIFO先进先出置换算法
 * > Author: incipe(吴华超)
 * > Language: cpp
 * > File Name: FIFO_Algorithm.h
 * > Created Time: Mon Nov 11 18:47:04 2019
 * > Email: chaoh7461@gmail.com
 * > Description:The story has just bugun!
 */

#ifndef _FIFO_ALGORITHM_
#define _FIFO_ALGORITHM_
#include<iostream>

class FIFO {
public:
	FIFO(int pages_, int blocks_);//构造函数
	~FIFO();//析构函数
	void Init(int pages, int blocks);//初始化
	void fifoAlgorithm(int pages, int blocks);//FIFO算法
	void print(int pages, int blocks);//打印
private:
	int pages;//页面数
	int blocks;//物理块
};


#endif //_FIFO_ALGORITHM_