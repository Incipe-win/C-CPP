#include <cstring>
#include <iostream>
#include <map>
#include <string>

int main() {
  using namespace std;
  int n;
  string str1;
  while (cin >> n) {
    if (n == 0)
      break;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> str1;
      mp[str1]++; // map的特点
    }
    map<string, int>::iterator it;
    string str;
    int sum = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second > sum) {
        str = it->first;
        sum = it->second; //找出最大的int，保存最大int的string
      }
    }
    cout << str << endl;
  }
  return 0;
}