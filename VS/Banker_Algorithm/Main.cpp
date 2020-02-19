
#include <iostream>
#include "BankerAlgorithm.h"
using namespace std;

int main() {
	cout << "-----------------------------银行家算法----------------------------------" << endl;
	BA Banker;
	Banker.Init();
	Banker.Safe();
	Banker.Banker();
	cout << endl;
	cout << __DATE__<<" ";
	cout << __TIME__ << endl<<endl;
	cout << "王胜伟的作品" << endl;
	cin.get();
	return 0;
}