#include "mystring.h"
#include <cstring>
#include <iostream>

using namespace std;

ostream &operator<<(ostream &cout, MyString &str) {
  cout << str.pString;
  return cout;
}

istream &operator>>(istream &cin, MyString &str) {
  if (str.pString != nullptr) {
    delete[] str.pString;
    str.pString = nullptr;
  }

  char buf[1024];
  cin >> buf;

  str.pString = new char[strlen(buf) + 1];
  strcpy(str.pString, buf);
  str.size = strlen(buf);
  // cin >> str.pString;

  return cin;
}

MyString::MyString(const char *str) {
  this->pString = new char[strlen(str) + 1];
  strcpy(this->pString, str);
  this->size = strlen(str);
}

MyString::MyString(const MyString &str) {
  this->pString = new char[strlen(str.pString) + 1];
  strcpy(this->pString, str.pString);
  this->size = str.size;
}

MyString::~MyString() {
  if (this->pString != nullptr) {
    delete[] this->pString;
  }
}

MyString &MyString::operator=(const char *str) {
  if (this->pString != nullptr) {
    delete[] this->pString;
    this->pString = nullptr;
  }
  this->pString = new char[strlen(str) + 1];
  strcpy(this->pString, str);
  return *this;
}
MyString &MyString::operator=(const MyString &str) {
  if (this->pString != nullptr) {
    delete[] this->pString;
    this->pString = nullptr;
  }
  this->pString = new char[strlen(str.pString) + 1];
  strcpy(this->pString, str.pString);
  return *this;
}

char &MyString::operator[](int index) { return this->pString[index]; }

MyString MyString::operator+(const MyString &str) {
  int newSize = this->size + strlen(str.pString) + 1;
  char *tmp = new char[newSize];
  memset(tmp, 0, newSize);
  strcat(tmp, this->pString);
  strcat(tmp, str.pString);

  MyString newStr(tmp);
  delete[] tmp;
  return newStr;
}

MyString MyString::operator+(const char *str) {
  int newSize = this->size + strlen(str) + 1;
  char *tmp = new char[newSize];
  memset(tmp, 0, newSize);
  strcat(tmp, this->pString);
  strcat(tmp, str);

  MyString newStr(tmp);
  delete[] tmp;
  return newStr;
}

bool MyString::operator==(const MyString &str) {
  if (strcmp(this->pString, str.pString)) {
    return false;
  } else {
    return true;
  }
}
bool MyString::operator==(const char *str) {
  if (strcmp(this->pString, str)) {
    return false;
  } else {
    return true;
  }
}