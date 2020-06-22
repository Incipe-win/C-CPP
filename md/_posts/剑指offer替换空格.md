## 原题

> 请实现一个函数，把字符串 `s` 中的每个空格替换成"%20"。
>
> **示例 1：**
>
> > 输入：s = "We are happy."
> > 输出："We%20are%20happy."
>
> **限制：**
>
> > 0 <= s 的长度 <= 10000
>
> 来源：力扣（LeetCode）
>
> 链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

## 思路

这个题感觉就十分简单了，但是，我竟然会想到按照空格拆分字符串再重新拼装，钻洞中💀

+ c++代码

````cpp
class Solution {
public:
  string replaceSpace(string s) {
    int size = s.size();
    vector<string> vec;
    string str;
    int j = 0;
    for (int i = 0; i < size; ++i) {
      if (s[i] == ' ') {
        vec.emplace_back(s.substr(j, i - j));
        j = i + 1;
      }
    }
    vec.emplace_back(s.substr(j, size));
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
      if (i != vec.size() - 1) {
        str += vec[i] + "%20";
      } else {
        str += vec[i];
      }
    }
    return str;
  }
};
````

是不是被我这个想法吓到了😂

我们重新定义一个字符串，遇到空格，就添加 `%20`，不是空格就把原来的字符加进去就好了。

+ c++代码

````cpp
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (auto &i : s) {
            if (i == ' ') {
                // ans.push_back('%');
                // ans.push_back('2');
                // ans.push_back('0');
                ans.append("%20");
            } else {
                // ans.push_back(i);
                ans.append(1, i);
            }
        }
        return ans;
    }
};
````

+ python代码

````python
class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(" ", "%20")
````

python轮子还是多，但是涉及到底层感觉就没有c/c++那么顺手了~

时间复杂度$O(N)$， 空间复杂度$O(N)$