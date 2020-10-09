/*
 * > 银行家避免死锁算法
 * > Author: incipe
 * > Language: cpp
 * > File Name: Banker_Algorithm.cpp
 * > Created Time: Mon Nov 4 21:33:04 2019
 * > Email: chaoh7461@gmail.com
 */

#include <iostream>
#include "BankerAlgorithm.h"
using namespace std;

const int MAXPROGRESS = 50;//最大进程数
const int MAXRESOUCES = 100;//最大资源数

int Available[MAXRESOUCES];//可利用资源向量
int Max[MAXPROGRESS][MAXRESOUCES];//最大需求矩阵
int Allocation[MAXPROGRESS][MAXRESOUCES];//分配矩阵
int Need[MAXPROGRESS][MAXRESOUCES];//需求矩阵
bool Finish[MAXPROGRESS];//标志向量
int P[MAXPROGRESS];//记录序列
int Request[MAXPROGRESS][MAXRESOUCES];//请求向量

int m, n;//资源种类,比如A,B,C...;//进程数

//初始化数据结构
void BA::Init() {
	cout << "请输入进程数:";
	cin >> m;
	cout << "请输入资源种类:";
	cin >> n;
	cout << "请输入每个进程最多所需的资源数,按照" << m << "x" << n << "矩阵输入" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Max[i][j];
		}
	}
	cout << "请输入每个进程已分配的资源数,也按照" << m << "x" << n << "矩阵输入" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Allocation[i][j];
			Need[i][j] = Max[i][j] - Allocation[i][j];
			//因为需求不可能小于0!
			if (Need[i][j] < 0) {
				cout << "你输入的第" << i + 1 << "个进程的第" << j + 1 << "个资源数错误,请重新输入" << endl;
				j--;
				continue;
			}
		}
	}
	cout << "请输入各个资源拥有的数目:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> Available[i];
	}
}

//打印结果表
void BA::Show() {
	cout << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "系统可用的资源数:";
	for (int j = 0; j < n; j++) {
		cout << " " <<Available[j];
	}
	cout << endl;
	cout << "系统还需的资源数:" << endl << endl;
	for (int i = 0; i < m; i++) {
		cout << "进程" << i << ":";
		for (int j = 0; j < n; j++) {
			cout << " " << Need[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "系统分配的资源量:" << endl << endl;
	for (int i = 0; i < m; i++) {
		cout << "进程" << i << ":";
		for (int j = 0; j < n; j++) {
			cout << " " << Allocation[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//求安全序列
bool BA::Safe() {
	int l = 0, i, j, k;
	int Work[MAXRESOUCES];
	for (int i = 0; i < n; i++) {
		Work[i] = Available[i];
	}
	fill(Finish, Finish + MAXPROGRESS, false);
	while (l < m) {
		int init_index = l;
		for (i = 0; i < m; i++) {
			if (Finish[i] == true) {
				continue;
			}
			for (j = 0; j < n; j++) {
				if (Need[i][j] > Work[j])
					break;
			}//二条件之一
			//如果都满足Need[i][j]<=Work[i][j],那么此时的j==n!
			if (j == n) {
				for (k = 0; k < n; k++) {
					Work[k] += Allocation[i][k];
				}
				Finish[i] = true;
				P[l++] = i;
			}
			else {
				continue;
			}
		}
		if (l == init_index) {
			cout << "系统是不安全的!" << endl;
			return false;//如果有Need[i][j]<Work[j]
		}
	}
	cout << "系统是安全的!" << endl;
	cout << "安全序列:" << endl;
	for (int i = 0; i < l; i++) {
		cout << P[i];
		if (i != l - 1) {
			cout << "-->";
		}
	}
	cout << "" << endl;
	return true;
}

void BA::Banker() {
	int i, cusneed, flag = 0;//cusneed是进程号
	string again;
	while (1) {
		BA::Show();
		cout << endl;
	Input:
		cout << "请输入需要资源的进程号:" << endl;
		cin >> cusneed;
		if (cusneed > m) {
			cout << "没有该进程!" << endl;
			goto Input;
		}
		cout << "请输入进程请求的各资源的数量" << endl;
		for (int i = 0; i < n; i++) {
			cin >> Request[cusneed][i];
		}
		for (i = 0; i < n; i++) {
			if (Request[cusneed][i] > Need[cusneed][i]) {
				cout << "您输入的请求数超过进程的需求量!请重新输入!" << endl;
				goto Input;
			}
			if (Request[cusneed][i] > Available[i]) {
				cout << "您输入的请求数超过系统有的资源数,请重新输入!" << endl;
				goto Input;
			}
		}
		for (i = 0; i < n; i++) {
			Available[i] -= Request[cusneed][i];
			Allocation[cusneed][i] += Request[cusneed][i];
			Need[cusneed][i] -= Request[cusneed][i];
		}
		if (BA::Safe()) {
			cout << "同意分配请求!" << endl;
		}
		else {
			cout << "您的请求被拒绝!" << endl;
			for (i = 0; i < n; i++) {
				Available[i] += Request[cusneed][i];
				Allocation[cusneed][i] -= Request[cusneed][i];
				Need[cusneed][i] += Request[cusneed][i];
			}
		}
		for (i = 0; i < n; i++) {
			if (Need[cusneed][i] <= 0) {
				flag++;
			}
		}
		if (flag == n) {
			for (i = 0; i < n; i++) {
				Available[i] += Allocation[cusneed][i];
				Allocation[cusneed][i] = 0;
				Need[cusneed][i] = 0;
			}
			cout << "线程" << cusneed << "占有资源被释放" << endl;
			flag = 0;
		}
		for (i = 0; i < m; i++) {
			Finish[i] = false;
		}
		cout << "您还要继续吗?是Y/y,任意键结束!" << endl;
		cin >> again;
		if (again == "Y" || again == "y") {
			continue;
		}
		break;
	}
}