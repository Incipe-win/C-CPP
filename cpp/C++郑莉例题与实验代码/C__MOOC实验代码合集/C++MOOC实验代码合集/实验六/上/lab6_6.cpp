#include "stdafx.h"

#include <iostream>
#include "employee.h"
using namespace std;

int main()
{
	Employee emp[5],*empOne=0;
	empOne = new Employee("Zhang San", "Haidian", "Beijing", "100084");
    emp[0] = * empOne;
    empOne = new Employee("Li Si", "Xuanwu", "Beijing", "100031");
	emp[1] = * empOne;
	empOne = new Employee("Wang Wu", "Nanfu", "Shanghai", "012345");
	emp[2] = * empOne;
	empOne = new Employee("Zhu Ge", "Wuhou", "Chengdu", "543210");
	emp[3] = * empOne;
	empOne = new Employee("Sun ying", "Zhifu", "Yantai", "264000");
    emp[4] = * empOne;

	for (int i = 0; i < 5; i ++) {
		cout << "Number" << i << ':' << endl;
		emp[i].display();
	}

   // emp[0].display();
	return 0;
}