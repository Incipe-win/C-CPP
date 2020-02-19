#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	if (auto x = 9; x > 10) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}