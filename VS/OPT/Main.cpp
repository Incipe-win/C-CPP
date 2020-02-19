/*
 * > OPT最佳置换算法
 * > Author: incipe(吴华超)
 * > Language: cpp
 * > File Name: Main.cpp
 * > Created Time: Sat Nov 9 18:47:04 2019
 * > Email: chaoh7461@gmail.com
 * > Description:The story has just bugun!
 */


#include<iostream>
#include<vector>
#include<algorithm>
#include"OPT_Algorithm.h"

using namespace std;

extern int cnt;

int main() {
	cout << "--------------------------------OPT最佳置换算法-------------------------------------" << endl;
	int pages_, blocks_;
	cout << "请输入页面数: ";
	cin >> pages_;
	cout << "请输入物理块数: ";
	cin >> blocks_;
	OPT OPT(pages_, blocks_);
	OPT.Init(pages_, blocks_);
	OPT.splAlgorithm(pages_, blocks_);
	cout << "置换次数为:" << cnt - 1 << endl << endl;
	cout << "缺页次数为:" << cnt + blocks_ - 1 << endl << endl;
	cout << "平均缺页率为:" << static_cast<double>(cnt + blocks_- 1) / static_cast<double>(pages_) << endl << endl;
	return 0;
}
