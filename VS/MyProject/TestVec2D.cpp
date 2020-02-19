#include<iostream>
using std::endl;
using std::cout;

int main() {
	//创建对象数组
	Vec2D v1{ 3,5 }, v2{ 4,6 };
	//转换为字符串
	cout << "v1= " << v1.tostring() << endl;
	cout << "v2= " << v2.tostring() << endl;
	//向量加法：向量+向量，向量+数
	Vec2D v3 = v1.add(v2);
	Vec2D v4 = v3.add(10);
	cout << "v3= " << v3.tostring() << endl;
	cout << "v4= " << v4.tostring() << endl;
	//向量减法，向量点积，向量数乘
	Vec2D v5 = v2.subtract(v1);
	Vec2D v6 = v2.dot(v1);
	Vec2D v7 = v3.multiply(2.1);
	cout << "v2 - v1 = " << v5.tostring() << endl;
	cout << "v2 . v1 = " << v6 << endl;
	cout << "v3 * 2.1 = " << v7.tostring() << endl;
	//向量求负值
	Vec2D v8 = v2.negative();
	//向量自增，向量自减
	cout << "++v8 = " << v8.increase().tostring() << endl;
	cout << "--v2 = " << v2.decrease().tostring() << endl;
	//读取或修改向量元素
	cout << "v1.x_ = " << v1.at(0) << endl;
	cout << "v1.y_ = " << v1.at(1) << endl;
	//求向量的角度和大小
	cout << "v1.magnitude = " << v1.magnitude() << endl;
	cout << "v1.direction = " << v1.direction() << endl;
	cout << "v1.comopare v2: " << v1.compareTo(v2) << endl;
}