/*
首先，用官方语言解释下什么叫分治算法
在计算机科学中，分治法是建基于多项分支递归的一种很重要的算法范式。
字面上的解释是“分而治之”，就是把一个复杂的问题分成两个或更多的相同或相似的子问题，
直到最后子问题可以简单的直接求解，原问题的解即子问题的解的合并。

这个技巧是很多高效算法的基础，如排序算法（快速排序、归并排序）、傅立叶变换（快速傅立叶变换）。

可以举个最简单的列子
比如：数组nums有5个元素1,3,4,2,5
我们要找到它最大的元素
那么，首先想到的是用该数组中的某一个元素记为temp，依次与其他元素比较，
比temp大元素，就用该元素替换temp，一次循环，就可找到最大元素
时间复杂度为o(n)

那么，分而治之的方法来了！
1,3,4,2,5
首先设置strat=0；end=strlen(nums)-1;
mid=(strat+end)/2;
我们在区间[strat,mid]找到最大的元素，记为max1
在[mid，end]找到最大的元素，记为max2
然后把比较max1,max2
最终得出最大元素
时间复杂度为o(n*logn)

代码如下：
#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (a > b ? a : b)

int GetMax(int nums[], int start, int end) {
  int max1, max2;
  if (start == end)
    return nums[start] = nums[end];
  else if (start + 1 == end)
    return max(nums[start], nums[end]);
  else {
    int mid = (start + end) / 2;
    max1 = GetMax(nums, start, mid);
    max2 = GetMax(nums, mid + 1, end);
    return max(max1, max2);
  }
  return 0;
}

int main() {
  int nums[5] = {1, 3, 4, 2, 5};
  cout << GetMax(nums, 0, 4) << endl;
  return 0;
}


 */
