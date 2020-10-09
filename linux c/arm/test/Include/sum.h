#ifndef _SUM_H_
#define _SUM_H_

int sum(int n) {
  int sum = 0;
  if (n % 2) {
    sum = (n + 1) / 2 * n;
  } else {
    sum = n / 2 * (n + 1);
  }
  return sum;
}

#endif  // _SUM_H_
