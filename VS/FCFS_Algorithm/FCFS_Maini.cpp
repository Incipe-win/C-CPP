/*
* > FCFS调度算法
* > Author:incipe(吴华超)
* > Language:cpp
* > File Name:FCFS_Main.cpp
* > Created Time:Sat Nov 2 21:33:04 2019
* > Email:chaoh7461@gmail.com
*/

#include <bits/stdc++.h>
#include"FCFS_Algorithm.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	FCFS FC[N];
	cout << "-------------------------FCFS调度算法-----------------------------" << endl
		<< endl;
	cout << "请输入进程数：";
	int ProgressNumbers;
	cin >> ProgressNumbers;
	for (int i = 0; i < ProgressNumbers; i++) {
		cout << "请输入进程名\t到达时间\t服务时间" << endl;
		cin >> FC[i].Progress >> FC[i].ArriveTime >> FC[i].ServerTime;
	}
	return 0;
}