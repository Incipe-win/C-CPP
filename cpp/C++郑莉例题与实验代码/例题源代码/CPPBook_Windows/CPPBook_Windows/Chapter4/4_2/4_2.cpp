//4_2.cpp
#include <iostream>
using namespace std;

class Point {	//Point 类的定义
public:		//外部接口
	Point(int xx = 0, int yy = 0) {	//构造函数
	x = xx;
		y = yy;
	}
	Point(const Point &p);	//拷贝构造函数
	void setX(int xx) 
	{x=xx;}
	void setY(int yy) 
	{y=yy;}

	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
private:	//私有数据
	int x, y;
};

//成员函数的实现
Point::Point(const Point &p) {
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor" << endl;
}

//形参为Point类对象的函数
void fun1(const Point& p) {
	cout << p.getX() << endl;
	//p.setX(1);
}

//返回值为Point类对象的函数
Point fun2() {
	Point a;
	return a;
}

//主程序
int main() {
	Point a;	//第一个对象A
	Point b(a);	//情况一，用A初始化B。第一次调用拷贝构造函数
	cout << b.getX() << endl;
	fun1(b);		//情况二，对象B作为fun1的实参。第二次调用拷贝构造函数
	b = fun2();		//情况三，函数的返回值是类对象，函数返回时，调用拷贝构造函数
	cout << b.getX() << endl;
	return 0;
}
