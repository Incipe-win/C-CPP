#ifndef MYARRAY_H_
#define MYARRAY_H_

#include <iostream>
using namespace std;

class MyArray {
public:
  MyArray();
  MyArray(int capacity);
  MyArray(const MyArray &array);

  ~MyArray();

  void push_back(int val);

  int getData(int index);

  void setData(int index, int val);

  int getSize();

  int getCapacity();

  int &operator[](int index);

private:
  int *pAddress;
  int size;
  int capacity;
};

#endif