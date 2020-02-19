#include<bits/stdc++.h>
using namespace std;

class FCFS_SPF {
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

const int N = 24;
FCFS_SPF FC[N];

void Print(int ProgressNumbers) {
	cout << fixed;
	cout << setprecision(3);
	double ATT;   //平均周转时间
	double A_QTT; //平均带权周转时间
	int sum1 = 0;
	for (int i = 0; i < ProgressNumbers; i++) {
		sum1 += FC[i].TT;
	}
	ATT = static_cast<double>(sum1) / N;
	double sum2 = 0;
	for (int i = 0; i < ProgressNumbers; i++) {
		sum2 += FC[i].QTT;
	}
	A_QTT = static_cast<double>(sum2) / N;
	cout << "\n进程名  到达时间  服务时间  开始执行时间  完成时间  周转时间  "
		"带权周转时间\n"
		<< endl;
	for (int i = 0; i < ProgressNumbers; i++) {
		cout << "  " << FC[i].Progress << "\t    " << FC[i].ArriveTime << "\t   "
			<< FC[i].ServerTime << "\t\t" << FC[i].StartTime << "\t   "
			<< FC[i].EndTime << "\t\t" << FC[i].TT << "\t  " << FC[i].QTT << "\t"
			<< endl;
	}
	cout << "\n"
		<< "平均周转时间为:" << ATT << endl;
	cout << "平均带权周转时间为:" << A_QTT << endl;
}

void SPF(int ProgressNumbers) {
	cout << "------------------------------------------------SPF算法---------------------------------------" << endl;
	// 按到达时间排序
	for (int i = 0; i < ProgressNumbers - 1; i++) {
		for (int j = 0; j < ProgressNumbers - i - 1; j++) {
			if (FC[j].ArriveTime > FC[j + 1].ArriveTime) {
				swap(FC[j].ArriveTime, FC[j + 1].ArriveTime);
				swap(FC[j].Progress, FC[j + 1].Progress);
				swap(FC[j].ServerTime, FC[j + 1].ServerTime);
			}
		}
	}
	FC[0].StartTime = FC[0].ArriveTime;
	FC[0].EndTime = FC[0].ServerTime + FC[0].StartTime;
	FC[0].TT = FC[0].EndTime - FC[0].ArriveTime;
	FC[0].QTT =
		static_cast<double>(FC[0].TT) / static_cast<double>(FC[0].ServerTime);
	//按服务时间排序
	for (int i = 0; i < ProgressNumbers - 1; i++) {
		for (int j = 1; j < ProgressNumbers - i - 1; j++) {
			if (FC[j].ServerTime > FC[j + 1].ServerTime) {
				swap(FC[j].ServerTime, FC[j + 1].ServerTime);
				swap(FC[j].ArriveTime, FC[j + 1].ArriveTime);
				swap(FC[j].Progress, FC[j + 1].Progress);
			}
		}
	}
	//计算除0时到达的进程的开始执行时间
	for (int i = 1; i < ProgressNumbers; i++) {
		//各进程的开始执行时间
		FC[i].StartTime = FC[i - 1].ServerTime + FC[i - 1].StartTime;
		//各进程的结束时间
		FC[i].EndTime = FC[i].ServerTime + FC[i].StartTime;
		//各进程的周转时间
		FC[i].TT = FC[i].EndTime - FC[i].ArriveTime;
		FC[i].QTT =
			static_cast<double>(FC[i].TT) / static_cast<double>(FC[i].ServerTime);
	}
	Print(ProgressNumbers);
}

void FCFS(int ProgressNumbers) {
	cout << "------------------------------------------------FCFS算法---------------------------------------" << endl;
	// 按到达时间排序
	for (int i = 0; i < ProgressNumbers - 1; i++) {
		for (int j = 0; j < ProgressNumbers - i - 1; j++) {
			if (FC[j].ArriveTime > FC[j + 1].ArriveTime) {
				swap(FC[j].ArriveTime, FC[j + 1].ArriveTime);
				swap(FC[j].Progress, FC[j + 1].Progress);
				swap(FC[j].ServerTime, FC[j + 1].ServerTime);
			}
		}
	}
	FC[0].StartTime = FC[0].ArriveTime;
	for (int i = 1; i < ProgressNumbers; i++) {
		FC[i].StartTime = FC[i - 1].ServerTime + FC[i - 1].StartTime;
		//计算各个进程的开始执行时间
	}
	for (int i = 0; i < ProgressNumbers; i++) {
		FC[i].EndTime = FC[i].ServerTime + FC[i].StartTime;
		// 计算各个进程完成时间
	}
	for (int i = 0; i < ProgressNumbers; i++) {
		FC[i].TT = FC[i].EndTime - FC[i].ArriveTime;
		//计算各个进程周转时间
	}
	for (int i = 0; i < ProgressNumbers; i++) {
		FC[i].QTT =
			static_cast<double>(FC[i].TT) / static_cast<double>(FC[i].ServerTime);
	}
	Print(ProgressNumbers);
}

int main() {
	cout << "-------------------------------SPF和FCFS调度算法--------------------------"
		"----------"
		<< endl
		<< endl;
	int ProgressNumbers; //进程数
	cout << "请输入进程数:";
	cin >> ProgressNumbers;
	for (int i = 0; i < ProgressNumbers; i++) {
		cout << "请输入进程名\t到达时间\t服务时间" << endl;
		cin >> FC[i].Progress >> FC[i].ArriveTime >> FC[i].ServerTime;
	}
	while (1) {
		cout << "请选择算法1.SPF 2.FCFS 3.退出 :";
		int choice;
		cin >> choice;
		if (choice == 1) {
			SPF(ProgressNumbers);
		}
		else if (choice == 2) {
			FCFS(ProgressNumbers);
		}
		else if (choice == 3) {
			cout << "祝您生活愉快!" << endl;
			break;
		}
		else
			cout << "输入非法,请重新输入!";
	}
	return 0;
}