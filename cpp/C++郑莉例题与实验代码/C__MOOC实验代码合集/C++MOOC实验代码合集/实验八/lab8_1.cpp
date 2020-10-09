#include <iostream>
using namespace std;

class Point
{
	int _x, _y;
public:
	Point(int x=0, int y=0) : _x(x), _y(y) {}
	Point& operator++();
	Point operator++(int);
	Point& operator--();
	Point operator--(int);
	friend ostream& operator << (ostream& o, Point& p);
};

Point& Point::operator++()
{
	_x++;
	_y++;
	return *this;
}
/* ++i在C++里面的定义最后返回的是被++的对象的引用（系统就是这么实现的），所以++i可以作为左值，即可以写：++i=3  */

//后缀式操作符接受一个额外的int型形参(不会使用它，仅做区分用)
Point Point::operator++(int)
{
	Point temp = *this;
	++*this; //复用了前缀++的重载
	return temp;

//后缀式版本中，返回值是尚未自增的原值，但对象本身已经做了自增操作了。

}
/* i++在C++里面的定义是，最后返回的是被++的对象的值（系统就是这么实现的），所以i++不可以作为左值，即不可以写：i++=3 */

Point& Point::operator--()
{
	_x--;
	_y--;
	return *this;
}

Point Point::operator--(int)
{
	Point temp = *this;
	--*this;
	return temp;
}

//友元函数，返回值类型为ostream&，可以支持<<级连操作
ostream& operator << (ostream& o, Point& p) {
	o << '(' << p._x << ", " << p._y << ')';
	return o;
}

int main()
{
	Point p(1, 2);
	cout << p << endl;
	cout << p++ << endl;
	cout << ++p << endl;
	cout << p-- << endl;
	cout << --p << endl;
	return 0;
}
