/*
 * > SPF调度算法
 * > Author: incipe(吴华超)
 * > Language: cpp
 * > File Name: SPF_Algorithm.cpp
 * > Created Time: Sun Nov 3 10:14:04 2019
 * > Email: chaoh7461@gmail.com
 * > Description: The story has just bugun!
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 24;

class SPF {
public:
	std::string Progress{ "" }; //进程名
	int ArriveTime{ 0 };        //到达时间
	int ServerTime{ 0 };        //服务时间
	int StartTime{ 0 };         //开始执行时间
	int EndTime{ 0 };           //结束时间
	int TT{ 0 };                //周转时间
	double ATT{ 0.0 };          //平均周转时间
	double QTT{ 0.0 };          //带权周转时间
	double A_QTT{ 0.0 };        //平均带权周转时间
};

SPF SP[N];

void SPF_Algorithm(int ProgressNumbers) {
	// 按到达时间排序
	for (int i = 0; i < ProgressNumbers - 1; i++) {
		for (int j = 0; j < ProgressNumbers - i - 1; j++) {
			if (SP[j].ArriveTime > SP[j + 1].ArriveTime) {
				swap(SP[j].ArriveTime, SP[j + 1].ArriveTime);
				swap(SP[j].Progress, SP[j + 1].Progress);
				swap(SP[j].ServerTime, SP[j + 1].ServerTime);
			}
		}
	}
	SP[0].StartTime = SP[0].ArriveTime;
	SP[0].EndTime = SP[0].ServerTime + SP[0].StartTime;
	SP[0].TT = SP[0].EndTime - SP[0].ArriveTime;
	SP[0].QTT =
		static_cast<double>(SP[0].TT) / static_cast<double>(SP[0].ServerTime);
	//按服务时间排序
	for (int i = 0; i < ProgressNumbers - 1; i++) {
		for (int j = 1; j < ProgressNumbers - i - 1; j++) {
			if (SP[j].ServerTime > SP[j + 1].ServerTime) {
				swap(SP[j].ServerTime, SP[j + 1].ServerTime);
				swap(SP[j].ArriveTime, SP[j + 1].ArriveTime);
				swap(SP[j].Progress, SP[j + 1].Progress);
			}
		}
	}
	//计算除0时到达的进程的开始执行时间
	for (int i = 1; i < ProgressNumbers; i++) {
		//各进程的开始执行时间
		SP[i].StartTime = SP[i - 1].ServerTime + SP[i - 1].StartTime;
		//各进程的结束时间
		SP[i].EndTime = SP[i].ServerTime + SP[i].StartTime;
		//各进程的周转时间
		SP[i].TT = SP[i].EndTime - SP[i].ArriveTime;
		SP[i].QTT =
			static_cast<double>(SP[i].TT) / static_cast<double>(SP[i].ServerTime);
	}
}

void Print(int ProgressNumbers) {
	cout << fixed;
	cout << setprecision(3);
	double ATT;   //平均周转时间
	double A_QTT; //平均带权周转时间
	int sum1 = 0;
	for (int i = 0; i < ProgressNumbers; i++) {
		sum1 += SP[i].TT;
	}
	ATT = static_cast<double>(sum1) / ProgressNumbers;
	double sum2 = 0;
	for (int i = 0; i < ProgressNumbers; i++) {
		sum2 += SP[i].QTT;
	}
	A_QTT = static_cast<double>(sum2) / ProgressNumbers;
	cout << "\n进程名  到达时间  服务时间  开始执行时间  完成时间  周转时间  "
		"带权周转时间\n"
		<< endl;
	for (int i = 0; i < ProgressNumbers; i++) {
		cout << "  " << SP[i].Progress << "\t    " << SP[i].ArriveTime << "\t   "
			<< SP[i].ServerTime << "\t\t" << SP[i].StartTime << "\t   "
			<< SP[i].EndTime << "\t\t" << SP[i].TT << "\t  " << SP[i].QTT << "\t"
			<< endl;
	}
	cout << "\n"
		<< "平均周转时间为:" << ATT << endl;
	cout << "平均带权周转时间为:" << A_QTT << endl;
}

int main() {
	cout << "-------------------------------SPF调度算法--------------------------"
		"----------"
		<< endl
		<< endl;
	int ProgressNumbers; //进程数
	cout << "请输入进程数:";
	cin >> ProgressNumbers;
	for (int i = 0; i < ProgressNumbers; i++) {
		cout << "请输入进程名\t到达时间\t服务时间" << endl;
		cin >> SP[i].Progress >> SP[i].ArriveTime >> SP[i].ServerTime;
	}
	SPF_Algorithm(ProgressNumbers);
	Print(ProgressNumbers);
	return 0;
}
