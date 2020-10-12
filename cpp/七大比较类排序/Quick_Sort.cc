#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int split(int low, int high, vector<int> &nums) {
  int temp = nums[low];
  while (low < high) {
    if (low < high && nums[high] >= temp) high--;
    nums[low] = nums[high];
    if (low < high && nums[low] <= temp) low++;
    nums[high] = nums[low];
  }
  nums[high] = temp;
  return high;
}

void quickSort(int low, int high, vector<int> &nums) {
  if (low >= high) return;
  int mid = split(low, high, nums);
  quickSort(low, mid - 1, nums);
  quickSort(mid + 1, high, nums);
}

int main() {
  vector<int> nums{8, 5, 6, 4, 2, 7, 3, 1, 9, 10};
  int len = nums.size();
  quickSort(0, len - 1, nums);
  vector<int>::iterator it;
  for (it = nums.begin(); it != nums.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}

/**
 * 浙大MOOC写法

typedef int ElementType;
ElementType Median3(ElementType A[], int Left, int Right) {
  int Center = (Left + Right) / 2;
  if (A[Left] > A[Center]) swap(A[Left], A[Center]);
  if (A[Left] > A[Right]) swap(A[Left], A[Right]);
  if (A[Center] > A[Right]) swap(A[Center], A[Right]);

  //此时A[Left] <= A[Center] <= A[Right]
  swap(A[Center], A[Right - 1]);//将基准Pivot藏到右边
  //只需要考虑A[Left + 1]...A[Right - 2]
  return A[Right - 1];//返回基准Pivot
}

void Qsort(ElementType A[], int Left, int Right) {
  int Pivot, Cutoff, Low, High;

  if (Cutoff <= Right - Left) {//如果序列元素充分多，进入快排
    Pivot = Median3(A, Left, Right);//选基准
    Low = Left;
    High = Right - 1;
    while (1) {//将此序列中比基准小的移到基准左边，大的移动到右边
      while (A[++Low] < Pivot)
        ;
      while (A[--High] > Pivot)
        ;
      if (Low < High)
        swap(A[Low], A[High]);
      else
        break;
    }
    swap(A[Low], A[Right - 1]);//将基准换到正确位置
    Qsort(A, Left, Low - 1);//递归解决左边
    Qsort(A, Low + 1, High);//递归解决右边
  } else {
    //调用插入排序
    // Insert_Sort(A + Left, Right - Left + 1);
  }
}

void QuickSort(ElementType A[], int N) {
  //统一接口
  Qsort(A, 0, N - 1);
}

*/