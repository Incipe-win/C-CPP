/*
 * > FCFS调度算法
 * > Author:incipe
 * > Language:cpp
 * > File Name:FCFS_Algorithm.cpp
 * > Created Time:Sat Nov 2 21:33:04 2019
 * > Email:chaoh7461@gmail.com
 */

#include <bits/stdc++.h>
using namespace std;

class FCFS {
public:
  string Progress{""}; //进程名字
  int ArriveTime{0};   //到达时间
  int ServerTime{0};   //服务时间
  int StartTime{0};    //开始执行时间
  int EndTime{0};      //结束时间
  int TT{0};           //周转时间
  double QTT{0.0};     //带权周转时间
};
const int N = 24; //最大进程数
FCFS FC[N];

void FCFS_Algorithm(int ProgressNumbers) {
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
}

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

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  cout << "-------------------------FCFS调度算法-----------------------------"
       << endl
       << endl;
  cout << "请输入进程数：";
  int ProgressNumbers;
  cin >> ProgressNumbers;
  for (int i = 0; i < ProgressNumbers; i++) {
    cout << "请输入进程名\t到达时间\t服务时间" << endl;
    cin >> FC[i].Progress >> FC[i].ArriveTime >> FC[i].ServerTime;
  }
  FCFS_Algorithm(ProgressNumbers);
  Print(ProgressNumbers);
  cout << endl;
  cout << __TIME__ << " ";
  cout << __DATE__ << endl << endl;
  cout << "incipe" << endl;
  return 0;
}