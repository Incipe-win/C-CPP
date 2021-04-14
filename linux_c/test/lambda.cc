#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Student {
 private:
  string name;
  int age;

 public:
  Student() { cout << "Hello World" << endl; }
  Student(string _name, int _age) : name(_name), age(_age) {
    cout << name << " " << age << endl;
  };
  int operator()() { return 11; }
  void print() { cout << "This is my print" << endl; }
};

int main() {
  // vector<int> arr(11, 0);
  // for (int i = 0; i < 11; ++i) {
  //     arr[i] = i + 1;
  // }
  // // auto arrayHash = [fn = hash<int>{}](const array<int, 26> &arr) ->
  // size_t
  // // {
  // //     return accumulate(arr.begin(), arr.end(), 0u,
  // //                       [&](size_t acc, int num) { return fn(num); });
  // // };
  // for (auto &it : arr) {
  //     cout << it << " ";
  // }
  // cout << endl;
  Student s = Student{"name", 11};
  s.print();
  cout << s() << endl;
  cout << typeid(s).name() << endl;
  // cout << typeof(s) << endl;
  return 0;
}
