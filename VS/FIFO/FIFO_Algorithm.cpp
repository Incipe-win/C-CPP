#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include"FIFO_Algorithm.h"
using namespace std;

vector<int>s;
vector<int>a;
int cnt = 0;

FIFO::FIFO(int _pages, int _blocks) :pages{ _pages }, blocks{ _blocks }{}

FIFO::~FIFO() {
	cout << "欢迎使用" << endl;
}

void FIFO::Init(int pages, int blocks) {
	cout << "请输入页面:" << endl;
	int tmp;
	for (int i = 0; i < pages; i++) {
		cin >> tmp;
		s.push_back(tmp);
	}
	cout << "页面为:" << endl;
	vector<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	for (int i = 0; i < blocks; i++) {
		a.push_back(s[i]);
	}
	FIFO::print(pages, blocks);
}

void FIFO::fifoAlgorithm(int pages, int blocks) {
	for()
}

void FIFO::print(int pages, int blocks) {
	cnt++;
	cout << endl;
	cout << "物理块为:" << endl;
	vector<int>::iterator it_;
	for (it_ = a.begin(); it_ != a.end(); it_++) {
		cout << *it_ << " ";
	}
	cout << endl;//打印
}