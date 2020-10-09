#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class MyOutRangeException : public exception {
public:
  MyOutRangeException(string errorInfo) { this->errorInfo = errorInfo; }
  virtual ~MyOutRangeException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {}

  /** Returns a C-style character string describing the general cause
   *  of the current error.  */
  virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
    return this->errorInfo.c_str();
  }

private:
  string errorInfo;
};

class Person {
public:
  Person(string name, int age) {
    this->name = name;
    if (age < 0 || age > 200) {
      throw MyOutRangeException("年龄越界了！");
    }
  }

private:
  string name;
};

void test01() {
  try {
    Person p("Jack", 300);
  } catch (MyOutRangeException &e) {
    cout << e.what() << endl;
  }
}

int main() {
  test01();
  return 0;
}
