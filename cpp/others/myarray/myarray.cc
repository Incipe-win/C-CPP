#include "myarray.h"
#include <iostream>

using namespace std;

int main() {
  MyArray *array = new MyArray(30);

  // MyArray *array2(array); 不会调用拷贝构造
  MyArray *array2 = new MyArray(*array);
  MyArray array3 = *array;
  delete array;

  for (int i = 0; i < 10; ++i) {
    array2->push_back(i);
  }

  for (int i = 0; i < 10; ++i) {
    cout << array2->getData(i) << endl;
  }

  array2->setData(10, 999);
  cout << array2->getData(10) << endl;

  cout << "array2's size is: " << array2->getSize() << endl;
  cout << "array2's capacity is: " << array2->getCapacity() << endl;

  delete array2;

  for (int i = 0; i < 10; ++i) {
    array3.push_back(i);
  }

  for (int i = 0; i < 10; ++i) {
    cout << array3.getData(i) << endl;
  }
  array3.setData(10, 999);
  cout << array3.getData(10) << endl;
  cout << "array3's size is: " << array3.getSize() << endl;
  cout << "array3's capacity is: " << array3.getCapacity() << endl;

  cout << "[] is load: " << array3[10] << endl;
  array3[0] = 999;
  for (int i = 0; i <= 10; ++i) {
    cout << array3[i] << endl;
  }
  return 0;
}
