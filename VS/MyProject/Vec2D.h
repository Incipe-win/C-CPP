#pragma once
class Vec2D{
public:
	Vec2D();
	Vec2D(double, double);
	~Vec2D();
private:
	double x_;
	double y_;
public:
	// 将向量转换为字符串形式表示
	std::string toString();
	// 加法
	Vec2D add(Vec2D secondVec2D);
};

