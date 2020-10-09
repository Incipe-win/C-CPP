#include <stdio.h>
#include <string.h>

#define MAX 3000

int main() {
  int A[MAX]; //定义数组
  int n, i, j, k;
  int s;                   //记录每个元素成以阶乘之后的数据
  int c = 0;               //记录需要的进位
  memset(A, 0, sizeof(A)); //将A数组初始化为0，memset函数需要string.h的头文件
  A[0] = 1;                //首先将a设为1
  scanf("%d", &n); //从键盘输入需要计算的阶乘
  //循环乘以阶乘，记录阶乘,注意边界n需要乘到
  for (i = 2; i <= n; i++) {
    //循环数组进行每个元素的相乘和进位
    for (j = 0; j < MAX; j++) {
      s = A[j] * i + c;
      c = s / 10; //保存需要进位的数据
      A[j] = s % 10;
    }
  }

  //接下来进行输出的时候应该是反着进行输出，并且输出应该是从后往前第一个不为0的开始
  //注意数组整个大小时MAX，从0开始所以最后一位是MAX-1
  for (i = MAX - 1; i >= 0; i--) {
    //通过循环控制是否找到第一个不为0的位置，如果一直为0，则一直循环
    if (A[i] != 0) {
      k = i;
      break; //当找到不为0的A[i]的时候就退出循环
    }
  }
  //反着输出
  for (j = k; j >= 0; j--) {
    printf("%d", A[j]);
  }
  return 0;
}