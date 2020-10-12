#include "myarray.h"

MyArray::MyArray() {
  this->capacity = 100;
  this->size = 0;
  this->pAddress = new int[this->capacity];
}

MyArray::MyArray(int capacity) {
  this->capacity = capacity;
  this->size = 0;
  this->pAddress = new int[this->capacity];
}

MyArray::MyArray(const MyArray &array) {
  this->pAddress = new int[array.capacity];
  this->size = array.size;
  this->capacity = array.capacity;

  for (int i = 0; i < array.size; ++i) {
    this->pAddress[i] = array.pAddress[i];
  }
}

MyArray::~MyArray() {
  if (this->pAddress != nullptr) {
    delete[] this->pAddress;
    this->pAddress = nullptr;
  }
}

void MyArray::push_back(int val) {
  this->pAddress[this->size] = val;
  this->size++;
}

int MyArray::getData(int index) { return this->pAddress[index]; }

void MyArray::setData(int index, int val) { this->pAddress[index] = val; }

int MyArray::getSize() { return this->size; }

int MyArray::getCapacity() { return this->capacity; }

int &MyArray::operator[](int index) { return this->pAddress[index]; }