## 原题

> 找出数组中重复的数字。
>
> 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
>
> 示例 1：
>
> >输入：
> >[2, 3, 1, 0, 2, 5, 3]
> >
> >输出：2 或 3 
>
> 限制：
>
> > 2 <= n <= 100000
>
> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof

## 思路

这题乍一看，好像不难😂

### Ⅰ. 排序

有点耍流氓的感觉~

````cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int size = nums.size();
      for (int i = 0; i < size; ++i) {
        if (nums[i] == nums[i + 1]) {
          return nums[i];
        }
      }
      return -1;
    }
};
````

时间复杂度 $O(nlogn)$， 空间复杂度$O(1)$

### Ⅱ. 哈希

哈希是不存重复值的，所以，每当我们遇到重复值后，把hash的value加一即可。

````cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            ++mp[nums[i]];
        }
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            if (it->second != 1) {
                return it->first;
            }
        }
        return -1;
    }
};
````

还要单独遍历一遍hash，不太好，优化下。

+ c++代码

````cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            ++mp[nums[i]];
            if (mp[nums[i]] > 1) {
                return nums[i];
            }
        }
        return 0;
    }
};
````

这题hash貌似不太强，可能是因为索引冲突太严重了，直接用个vector快多了。

+ python代码

````python
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        size = len(nums)
        res = [0 for i in range(size)]
        for i in range(size):
            res[nums[i]] += 1
            if res[nums[i]] > 1:
                return nums[i]
        return -1
````

时间复杂度$O(n)$，空间复杂度$O(n)$

接下来是本题的重头戏了！

### Ⅲ. 抽屉原理(鸽巢原理)

[抽屉原理](https://baike.baidu.com/item/抽屉原理/233776?fromtitle=鸽巢原理&fromid=731656)

+ c++代码

````cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            while (i != nums[i]) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};
````

+ python代码

````python
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        size = len(nums)
        for i in range(size):
            while i != nums[i]:
                if nums[i] == nums[nums[i]]:
                    return nums[i]
                tmp = nums[i]
                nums[i] = nums[tmp]
                nums[tmp] = tmp
        return -1
````

时间复杂度$O(n)$， 空间复杂度$O(1)$

由于笔者本身水平有限，鸽巢原理解释起来还是有点牵强，故暂时没有给详细的解析原理。

看到此代码就懂什么意思，但是自己写出来还是做不到。见谅🙏

## 总结

三人行，必有我师焉，一起看看其他大牛的代码，学会阅读源码，也是一项必备的技能。

[数组中重复的数字](https://krahets.gitee.io/views/sword-for-offer/2020-02-20-sword-for-offer-03.html#解题思路：)

````python
class Solution:
    def findRepeatNumber(self, nums: [int]) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == i:
                i += 1
                continue
            if nums[nums[i]] == nums[i]: return nums[i]
            nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return -1
````

[O(1)空间 非交换，数组做哈希](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/o1kong-jian-fei-jiao-huan-shu-zu-zuo-ha-xi-by-ray-/)

````cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[abs(nums[i])]<0)
                return abs(nums[i]);
            nums[abs(nums[i])]*=-1;
        }
        return find(nums.begin(),nums.end(),0)-nums.begin();
    }
};
````

[把数组视为哈希表，找到重复的数就是发生了哈希冲突](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/tong-de-si-xiang-by-liweiwei1419/)

````java
import java.util.Arrays;

public class Solution {

    public int findRepeatNumber(int[] nums) {
        int len = nums.length;

        for (int i = 0; i < len; i++) {
            // 如果当前的数 nums[i] 没有在下标为 i 的位置上，就把它交换到下标 i 上
            // 交换过来的数还得做相同的操作，因此这里使用 while
            // 可以在此处将数组输出打印，观察程序运行流程
            // System.out.println(Arrays.toString(nums));

            while (nums[i] != i) {

                if (nums[i] == nums[nums[i]]) {
                    // 如果下标为 nums[i] 的数值 nums[nums[i]] 它们二者相等
                    // 正好找到了重复的元素，将它返回
                    return nums[i];
                }
                swap(nums, i, nums[i]);
            }
        }
        throw new IllegalArgumentException("数组中不存在重复数字！");
    }

    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

}
````

## 诗情画意

> <center>天净沙·夏</center>
> <center>白朴</center>
> <center>云收雨过波添，楼高水冷瓜甜，绿树阴垂画檐。</center>
> <center>沙厨藤簟(diàn)，玉人罗扇轻缣(jiān)。</center>

