#include <sys/ptrace.h>
#include <unistd.h>

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int antiDbg() {
  if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1) {
    cout << "You are using a Debugger!\n:)\n";
    return 1;
  }
  return 0;
}

int main() {
  int a = antiDbg();
  if (a == 1) {
    return 1;
  } else {
    cout << "No debugger detected!\n";
    for (int i = 0; i < 999; ++i) {
      printf("Hello, world!(%d)\n", i);
      sleep(1);
    }
  }
  return 0;
}
