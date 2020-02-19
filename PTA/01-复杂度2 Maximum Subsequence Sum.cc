/*英语不好害死人，把题目理解错了。WA了好多次！*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> s;

void MaxSubquence(vector<int> s, int k) {
  int Max = 0, tmp, StartIndex = 0, EndIndex = 0, flag = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] < 0)
      flag++;
    tmp = 0;
    for (int j = i; j < k; j++) {
      tmp += s[j];
      if (tmp > Max) {
        StartIndex = s[i];
        EndIndex = s[j];
        Max = tmp;
      }
    }
  }
  if (flag == k)
    cout << 0 << " " << s[0] << " " << s[k - 1] << endl;
  else
    cout << Max << " " << StartIndex << " " << EndIndex << endl;
}

int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int tmp;
    cin >> tmp;
    s.push_back(tmp);
  }
  MaxSubquence(s, k);
  return 0;
}