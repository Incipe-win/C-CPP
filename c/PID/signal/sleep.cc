#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> ans;
unordered_map<pid_t, int> mp;
int count;

template <class T>
void print(const T &array) {
  for (int number : array) {
    cout << number << " ";
  }
  cout << endl;
}

void creat_numbers(int count) {
  for (int i = 0; i < count; ++i) {
    int temp = rand() % 10 + 1;
    vec.emplace_back(temp);
  }
  cout << "before sort: ";
  print(vec);
}

void catch_sig(int value, siginfo_t *info, void *p) {
  pid_t pid = info->si_pid;
  int temp = mp[pid];
  ans.emplace_back(temp);
  printf("pid %d touch %d number, is waked\n", pid, value);
}

void create_process(int count) {
  struct sigaction act;
  act.sa_flags = 0;
  act.sa_sigaction = catch_sig;
  sigemptyset(&act.sa_mask);
  sigaction(SIGALRM, &act, NULL);
  int i;
  pid_t pid;
  for (i = 0; i < count; ++i) {
    pid = fork();
    if (pid == 0) {
      break;
    }
  }
  for (int j = 0; j < count; ++j) {
    cout << "-----" << endl;
    mp[getpid()] = vec[i];
    struct itimerval myit = {{0, 0}, {vec[j], 0}};
    setitimer(ITIMER_REAL, &myit, NULL);
    break;
  }
  if (i == 10) {
    for (i = 0; i < count; ++i) {
      wait(NULL);
    }
  }
}

int main() {
  int count = 10;
  srand((unsigned int)time(nullptr));
  creat_numbers(count);
  create_process(10);
  cout << "sort after: ";
  print(ans);
  return 0;
}
