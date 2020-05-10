/*方法一*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int s[100001];

int MaxSubsequence(int s[], int K) {
  int Max = 0, tmp;
  for (int i = 0; i < K; i++) {
    tmp = s[i];
    for (int j = i + 1; j < K; j++) {
      tmp += s[j];
      if (tmp > Max) {
        Max = tmp;
      }
    }
  }
  return Max;
}

int main() {
  int K;
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> s[i];
  }
  cout << MaxSubsequence(s, K) << endl;
  return 0;
}

/*方法二*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int s[100001];

int MaxSubsequence(int s[], int K) {
  int Max = 0, tmp = 0;
  for (int i = 0; i < K; i++) {
    tmp += s[i];
    if (tmp > Max) { 
        Max = tmp;
    }
    if (tmp < 0) {
      tmp = 0;
    }
  }
  return Max > 0 ? Max : 0;
}

int main() {
  int K;
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> s[i];
  }
  cout << MaxSubsequence(s, K) << endl;
  return 0;
}
