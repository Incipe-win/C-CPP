#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include"FIFO_Algorithm.h"

using namespace std;
extern int cnt;

int main() {
	cout << "-----------------------------------FIFO置换算法------------------------------------" << endl;
	int pages_, blocks_;
	cout << "请输入页面数:";
	cin >> pages_;
	cout << "请输入物理块数:";
	cin >> blocks_;
	FIFO fi(pages_, blocks_);
	fi.Init(pages_, blocks_);
	fi.fifoAlgorithm(pages_, blocks_);
}