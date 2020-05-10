---
title: hdu1004(map解法)
categories: 
- Algorithm
tags: 
- 博客
---
<td align="center"><h1 style="color:#1A5CC8">Let the Balloon Rise</h1><font><b><span style="font-family:Arial;font-size:12px;font-weight:bold;color:green">Time Limit: 2000/1000 MS (Java/Others)&nbsp;&nbsp;&nbsp;&nbsp;Memory Limit: 65536/32768 K (Java/Others)<br>Total Submission(s): 168777&nbsp;&nbsp;&nbsp;&nbsp;Accepted Submission(s): 67277<br></span></b></font><br><br><div class="panel_title" align="left">Problem Description</div> <div class="panel_content">Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.<br><br>This year, they decide to leave this lovely job to you. <br></div><div class="panel_bottom">&nbsp;</div><br><div class="panel_title" align="left">Input</div> <div class="panel_content">Input contains multiple test cases. Each test case starts with a number N (0 &lt; N &lt;= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters.<br><br>A test case with N = 0 terminates the input and this test case is not to be processed.<br></div><div class="panel_bottom">&nbsp;</div><br><div class="panel_title" align="left">Output</div> <div class="panel_content">For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case.<br></div><div class="panel_bottom">&nbsp;</div><br><div class="panel_title" align="left">Sample Input</div><div class="panel_content"><pre><div style="font-family:Courier New,Courier,monospace;">5
green
red
blue
red
red
3
pink
orange
pink
0</div><div class="panel_bottom">&nbsp;</div><div class="panel_title" align="left">Sample Output</div><div class="panel_content"><pre><div style="font-family:Courier New,Courier,monospace;">red
pink</div><br><br>

```cpp
#include <cstring>
#include <iostream>
#include <map>
#include <string>

int main() {
  using namespace std;
  int n;
  string str1;
  while (cin >> n) {
    if (n == 0)
      break;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> str1;
      mp[str1]++; // map的特点
    }
    map<string, int>::iterator it;
    string str;
    int sum = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second > sum) {
        str = it->first;
        sum = it->second; //找出最大的int，保存最大int的string
      }
    }
    cout << str << endl;
  }
  return 0;
}
```



