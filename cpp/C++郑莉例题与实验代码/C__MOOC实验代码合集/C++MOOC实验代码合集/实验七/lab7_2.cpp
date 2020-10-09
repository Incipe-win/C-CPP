#include "stdafx.h"

#include <iostream>
using namespace std;

class BaseClass {
public:
	int Number;
	int getNumber() {return Number;}
	BaseClass(){ cout<<"BaseClass construct"<<endl;}
	~BaseClass(){ cout<<"BaseClass destruct"<<endl;}
};

class DerivedClass : BaseClass {
public:
	DerivedClass() {
		Number = 0;
		Number ++;
		cout << "DerivedClass Construction. Number = " << getNumber() << endl;
	}
	~DerivedClass() {
		Number --;
		cout << "DerivedClass Destruction. Number = " << getNumber() << endl;
	}
};

int main()
{
	DerivedClass d;
	return 0;
}
