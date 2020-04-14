#include "mystring.h"
#include <iostream>

using namespace std;

void test01() {
  MyString str = "abc";
  cout << str << endl;
  cout << "Please input a new content: ";
  cin >> str;
  cout << "new content is: " << str << endl;

  MyString str2(str);

  MyString str3 = "";
  str3 = str2;
  MyString str4 = "";
  str4 = "aaaa";
  MyString str5;
  cout << "str3: " << str3 << endl;
  cout << "str4: " << str4 << endl;
  str5 = "abc";
  cout << "old str5: " << str5 << endl;
  str5 = str3;
  cout << "new str5: " << str5 << endl;

  str3[0] = 'w';

  cout << "str3 first area is: " << str3[0] << endl;

  str4 = str + str2;

  cout << "link old str4 is: " << str4 << endl;

  str4 = str4 + "aa";

  cout << "link new str4 is: " << str4 << endl;

  if (str3 == str4) {
    cout << "str3 is equal str4" << endl;
  } else {
    cout << "str3 isn't equal str4" << endl;
  }

  MyString str7 = str4;
  if (str7 == str4) {
    cout << "str7 is equal str4" << endl;
  } else {
    cout << "str7 isn't equal str4" << endl;
  }
}

int main() {
  test01();
  return 0;
}