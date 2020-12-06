#include <unistd.h>

#include <ctime>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> ans;
int sum = 0;

template <class T>
void print(const T &array) {
  for (int num : array) {
    cout << num << " ";
  }
  cout << endl;
}

void create_numbers(int cnt) {
  for (int i = 0; i < cnt; ++i) {
    int tmp = rand() % 10 + 1;
    sum += tmp;
    vec.emplace_back(tmp);
  }
  cout << "before sort: ";
  print(vec);
}

void *func(void *arg) {
  sleep(*(int *)arg);
  ans.emplace_back(*(int *)arg);
  return NULL;
}

int main() {
  srand((unsigned int)time(nullptr));
  int cnt = 10;
  create_numbers(cnt);
  pthread_t tid[cnt];
  int i;
  for (i = 0; i < cnt; ++i) {
    int *argc = new int(vec[i]);
    pthread_create(&tid[i], NULL, func, (void *)argc);
    pthread_detach(tid[i]);
  }
  sleep(sum);
  cout << "sort after: ";
  print(ans);
  return 0;
}
