#include "stdafx.h"

#include <iostream>
using namespace std;

class Vehicle
{
public:
	int MaxSpeed;
	int Weight;
	void Run(){cout<<"Vehicle run"<<endl;};
	void Stop(){cout<<"Vehicle stop"<<endl;};

};

class Bicycle : virtual public Vehicle
{
public:
	int Height;
};

class Motorcar : virtual public Vehicle
{
public:
	int SeatNum;
};

class Motorcycle : public Bicycle, public Motorcar
{
};

int main()
{
	Motorcycle m;

	m.Height=1;
	m.SeatNum=2;
	m.Weight=100;
	m.MaxSpeed=60;
	
	m.Run();
	m.Stop();

	return 0;
}

