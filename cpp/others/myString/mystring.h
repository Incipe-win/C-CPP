#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <iostream>
using namespace std;

class MyString {
  friend istream &operator>>(istream &cin, MyString &str);
  friend ostream &operator<<(ostream &cout, MyString &str);

public:
  MyString() = default;
  MyString(const char *str);
  MyString(const MyString &str);

  ~MyString();

  MyString &operator=(const char *str);
  MyString &operator=(const MyString &str);

  char &operator[](int index);

  MyString operator+(const MyString &str);
  MyString operator+(const char *str);

  bool operator==(const MyString &str);
  bool operator==(const char *str);

private:
  char *pString;
  int size;
};

#endif // MY_STRING_H_