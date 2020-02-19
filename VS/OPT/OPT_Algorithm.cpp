/*
 * > OPT最佳置换算法
 * > Author: incipe(吴华超)
 * > Language: cpp
 * > File Name: OPT_Algorithm.cpp
 * > Created Time: Sat Nov 9 18:47:04 2019
 * > Email: chaoh7461@gmail.com
 * > Description:The story has just bugun!
 */

#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include"OPT_Algorithm.h"
using namespace std;

vector<int>a;//物理块向量
vector<int>s;//页面向量
int cnt = 0;

OPT::OPT(int _pages, int _blocks) :pages{ _pages }, blocks{ _blocks }{}//构造函数传参数

void OPT::Init(int pages, int blocks) {
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
	OPT::print(pages, blocks);
}//初始化数据

int _Find(int pages, int blocks,int t) {
	int* cmp = new int[3]{0};
	int tmp = 0;
	bool flag = false;
	for (int j = 0; j < blocks; j++) {
		for (int i = t+1; i < pages; i++) {
			if (s[i] == a[j]) {
				cmp[tmp++] = i;
				flag = true;
				break;
			}
		}
		if (flag) {
			flag = false;
			continue;
		}
		if (cmp[j]<blocks || cmp[j]>pages) {
			return j;
		}
	}
	return max(cmp[0], max(cmp[1], cmp[2]));
}//找最近未使用的页面

void OPT::splAlgorithm(int pages, int blocks) {
	bool flag = false;
	int x = 3;
	for (vector<int>::iterator i = s.begin() + 3; i != s.end(); i++) {
		for (vector<int>::iterator j = a.begin(); j != a.end(); j++) {
			if (*i == *j) {
				flag = true;
				break;
			}
		}
		if (flag) {
			flag = false;
			x++;
			continue;
		}
		else {
			int temp = _Find(pages, blocks, x);
			if (temp < 3) {
				a[temp] = *i;
				OPT::print(pages, blocks);
				x++;//为出现过的页面特殊置换处理
			}
			else {
				for (int j = 0; j < blocks; j++) {
					if (a[j] == s[temp]) {
						a[j] = *i;
						OPT::print(pages, blocks);
						x++;
						break;//置换页面
					}
				}
			}
		}
	}
	cout << endl;
}

void OPT::print(int pages, int blocks) {
	cnt++;
	cout << endl;
	cout << "物理块为:" << endl;
	vector<int>::iterator it_;
	for (it_ = a.begin(); it_ != a.end(); it_++) {
		cout << *it_ << " ";
	}
	cout << endl;//打印
}

OPT::~OPT() {
	cout << "欢迎使用!" << endl;
}
