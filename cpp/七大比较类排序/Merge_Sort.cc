#include <iostream>
#include <vector>
using namespace std;

/*归并排序：典型的分而治之
 * 1.分
 * 2.治
 */

//最大数组
const int MAX = 5;

//排序
void mergeSort(int *nums, int start, int mid, int end) {
  int *tmp = new int[end - start + 1];  //保存排好序的临时数组
  int i = start, j = mid + 1, k = 0;    //排序指针
  while (i <= mid && j <= end) {
    //从大到小排序
    if (nums[i] >= nums[j]) {
      tmp[k++] = nums[i++];
    } else {
      tmp[k++] = nums[j++];
    }
  }
  //还有未排完的数组
  while (i <= mid) {
    tmp[k++] = nums[i++];
  }
  while (j <= end) {
    tmp[k++] = nums[j++];
  }
  //合并到nums里面
  for (int i = 0; i < k; ++i) {
    nums[i + start] = tmp[i];
  }
  //释放空间
  delete[] tmp;
}
void merge(int *nums, int start, int end) {
  // nullptr
  if (nums == nullptr || start >= end) return;
  int mid = start + (end - start) / 2;
  //分前半部分
  merge(nums, start, mid);
  //分后半部分
  merge(nums, mid + 1, end);
  //治
  mergeSort(nums, start, mid, end);
}

int main() {
  int *nums = new int[MAX];
  for (int i = 0; i < MAX; i++) {
    cin >> nums[i];
  }
  merge(nums, 0, MAX - 1);
  for (int i = 0; i < MAX; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  delete[] nums;
  return 0;
}

/**
 * 浙大MOOC写法(递归)
 */
/*
// L = 左边起始位置，R = 右边起始位置，RightEnd = 右边终点位置
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd) {
  //将有序的A[L] ~ A[R - 1]和A[R] ~ A[RightEnd]归并成一个有序序列
  int LeftEnd, NumElements, Tmp;
  int i;

  LeftEnd = R - 1;//左边终点位置
  Tmp = L;//有序序列的起始位置
  NumElements = RightEnd - L + 1;

  while(L <= LeftEnd && R <= RightEnd) {
    if(A[L] <= A[R])
      TmpA[Tmp++] = A[L++];//将左边元素复制到TmpA
    else
      TmpA[Tmp++] = A[R++];// 将右边元素复制到TmpA
  }

  while(L <= LeftEnd)
    TmpA[Tmp++] = A[L++];//直接复制左边剩下的
  while(R <= RightEnd)
    TmpA[Tmp++] = A[R++];//直接复制右边剩下的
  for(i = 0; i < NumElements; ++i, RightEnd--)
    A[RightEnd] = TmpA[RightEnd];//将有序的TmpA赋值回A
}

void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd) {
  int Center;
  if(L < RightEnd) {
    Center = (L + RightEnd) / 2;
    Msort(A, TmpA, L, Center);//递归解决左边
    Msort(A, TmpA, Center + 1, RightEnd);//递归解决右边
    Merge(A, TmpA, L, Center + 1, RightEnd);//合并两段有序序列
  }
}

void MergeSort(ElementType A[], int N) {
  ElementType *TmpA;
  TmpA = (ElementType *)malloc(N * sizeof(ElementType));

  if(TmpA != NULL) {
    Msort(A, TmpA, 0, N - 1);
    free(TmpA);
  }
  else
    printf("空间不足");
}
*/

/*非递归
Merge同上

void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length) {
  //length当前有序子列长度
  int i, j;
  for(i = 0; i < N - 2 * length; i += 2 * length)
    Merge(A, TmpA, i, i + length, i + 2 * length - 1);
  if(i + length < N) //归并最后两个子列
    Merge(A, TmpA, i, i + length, N - 1);
  else //最后剩下一个子列
    for(j = i; j < N; j++)
      TmpA[j] = A[j];
}

void Merge_Sort(ElementType A[], int N) {
  int length;
  ElementType *TmpA;

  length = 1;//初始化子序列长度
  TmpA = malloc(N * sizeof(ElementType));
  if(TmpA != NULL) {
    while(length < N) {
      Merge_pass(A, TmpA, N, length);
      length *= 2;
      Merge_pass(TmpA, A, N, length);
      length *= 2;
    }
    free(TmpA);
  }
  else
    printf("空间不足");
}
*/