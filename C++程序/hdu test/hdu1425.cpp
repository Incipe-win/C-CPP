#include <bits/stdc++.h>
using namespace std;

int nums[1000000 + 6];
int n, m;

int split(int nums[], int low, int high);
void QuickSort(int nums[], int low, int high);

void QuickSort(int nums[], int low, int high) {
  int mid;

  if (low >= high)
    return;
  mid = split(nums, low, high);

  QuickSort(nums, low, mid - 1);
  QuickSort(nums, mid + 1, high);
}

int split(int nums[], int low, int high) {
  int temp = nums[low];
  while (low < high) {
    while (low < high && nums[high] <= temp)
      high--;
    nums[low] = nums[high];
    while (low < high && nums[low] >= temp)
      low++;
    nums[high] = nums[low];
  }

  nums[high] = temp;
  return high;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    QuickSort(nums, 0, n - 1);
    for (int i = 0; i < m; ++i) {
      if (i == m - 1)
        cout << nums[i] << endl;
      else
        cout << nums[i] << " ";
    }
  }
  return 0;
}
