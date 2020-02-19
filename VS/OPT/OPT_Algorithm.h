/*
 * > OPT最佳置换算法
 * > Author: incipe(吴华超)
 * > Language: cpp
 * > File Name: OPT_Algorithm.h
 * > Created Time: Sat Nov 9 18:47:04 2019
 * > Email: chaoh7461@gmail.com
 * > Description:The story has just bugun!
 */

#ifndef OPT_ALGORITHM_H_INCLUDED
#define OPT_ALGORITHM_H_INCLUDED

#include<iostream>
#include<array>
#include<algorithm>

class OPT {
public:
	OPT(int _pages, int _blocks);//构造函数
	~OPT();//析构函数
	void Init(int pages, int blocks);//初始化
	void splAlgorithm(int pages, int blocks);//OPT最佳置换算法
	void print(int pages, int blocks);//输出
private:
	int pages;//页面数
	int blocks;//物理块数
};


#endif // OPT_ALGORITHM_H_INCLUDED
