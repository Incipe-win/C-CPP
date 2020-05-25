## 原题

> 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
>
> **示例:**
>
> 现有矩阵 matrix 如下
>
> > [
> >   [1,   4,  7, 11, 15],
> >   [2,   5,  8, 12, 19],
> >   [3,   6,  9, 16, 22],
> >   [10, 13, 14, 17, 24],
> >   [18, 21, 23, 26, 30]
> > ]
>
> 给定 target = 5，返回 true。
>
> 给定 target = 20，返回 false。
>
> 限制：
>
> 0 <= n <= 1000
>
> 0 <= m <= 1000
>
> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof

## 思路

### Ⅰ. 暴力解决

直接遍历整个二维数组，找到target返回。

````cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (auto i = matrix.begin(); i != matrix.end(); ++i) {
            for (auto j = i->begin(); j != i->end(); ++j) {
                if (*j == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
````

时间复杂度$O(n * m)$，空间复杂度$O(1)$

### Ⅱ. 优化

通过题目我们知道，这是一个特殊的矩阵。

+ **右上角元素：** 所在列为最小元素，所在行为最大元素
+ **左下角元素：** 所在列为最大元素，所在行为最小元素

![](https://imgkr.cn-bj.ufileos.com/3827a534-aca6-4452-ae86-8afe25644823.gif)

+ 算法流程（从右上角开始）
  + 如果当前$matrix[i][j] > target$，说明当前列都大于$target$，消除当前列；
  + 如果当前$matrix[i][j] < target$， 说明当前行都小于$target$，消除当前行；
  + 如果当前$matrix[i][j] == target$， 说明二维数组中有$target$，返回；
  + 如果遍历完整个数组，都没有满足$matrix[i][j] == target$， 说明当前二维数组不存在一个数等于$target$。
+ c++代码

````cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        int n = 0, m = cols - 1;
        while (n < rows && m >= 0) {
            if(matrix[n][m] > target) {
                --m;
            } else if (matrix[n][m] < target) {
                ++n;
            } else {
                return true;
            }
        }
        return false;
    }
};
````

+ python代码

````python
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0:
            return False
        rows = len(matrix)
        cols = len(matrix[0])
        n, m = 0, cols - 1
        while n < rows and m >= 0:
            if matrix[n][m] < target:
                n += 1
            elif matrix[n][m] > target:
                m -= 1
            else:
                return True
        return False
````

时间复杂度$O(n + m), n, m为二维数组的行数和列数$， 空间复杂度$O(1)$