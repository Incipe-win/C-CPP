#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

unordered_map<int, int> Track1;
unordered_map<int, int> Move;
double Average;

void FCFS(unordered_map<int, int> Track, int Track_head, int Request) {
  int sum = 0;
  Move[0] = abs(Track_head - Track[0]);
  for (int i = 1; i < Request; i++) {
    Move[i] = abs(Track[i] - Track[i - 1]);
    sum += Move[i];
  }
  cout << "磁道起始位置:" << Track_head << endl;
  cout << "被访问的下一个磁道号"
       << "\t"
       << "移动距离" << endl;
  for (int i = 0; i < Request; i++) {
    cout << "  " << Track[i] << "\t\t\t" << Move[i] << endl;
  }
  cout << "平均寻道长度:" << static_cast<double>(sum) / Request << endl;
  cout << endl;
}

void S_STF(unordered_map<int, int> Track, int Track_head, int Request) {
  cout << "磁道起始位置:" << Track_head << endl;
  cout << "被访问的下一个磁道号"
       << "\t"
       << "移动距离" << endl;
  int temp[Request], tmp, sum = 0;
  Move[0] = 0x3f3f3f3f;
  for (int j = 0; j < Request; j++) {
    for (int i = 0; i < Request; i++) {
      temp[i] = abs(Track[i] - Track_head); //计算出各个磁道与初始磁道号的距离
    }
    for (int i = 0; i < Request; i++) {
      //如果当前i下标的磁道号时最小的,那么d会等于Request,相当于一个计数变量
      int d = 0;
      for (int k = 0; k < Request; k++) {
        //找到距离最小的磁道
        if (temp[i] <= temp[k]) {
          d++;
        }
      }
      if (d == Request) {
        cout << "  " << Track[i] << "\t\t\t";
        Move[j] = temp[i];
        cout << Move[j] << endl;
        Track_head = Track[i];
        Track[i] = 0x3f3f3f3f; //使用过了,不需要使用了.
      }
    }
    sum += Move[j];
  }
  cout << "平均寻道长度:" << static_cast<double>(sum) / Request << endl;
  cout << endl;
}

void SCAN(unordered_map<int, int> Track, int Track_head, int Request) {
  cout << "磁道起始位置:" << Track_head << endl;
  cout << "被访问的下一个磁道号"
       << "\t"
       << "移动距离" << endl;
  //当前磁道号里外数目,磁道号里外的磁道
  //判断当前磁道号里外的数目
  int inside = 0, outside = 0, in[Request], out[Request], tmp = 0;
  int temp[Request], sum = 0;
  for (int i = 0; i < Request; i++) {
    if (Track[i] >= Track_head) {
      out[outside++] = Track[i];
    } else {
      in[inside++] = Track[i];
    }
  }
  for (int p = 0; p < outside; p++) {
    for (int i = 0; i < outside; i++) {
      temp[i] = abs(out[i] - Track_head);
    }
    for (int i = 0; i < outside; i++) {
      int d = 0;
      for (int j = 0; j < outside; j++) {
        if (temp[i] <= temp[j]) {
          d++;
        }
      }
      if (d == outside) {
        cout << "  " << out[i] << "\t\t\t";
        Move[p] = temp[i];
        cout << Move[i] << endl;
        Track_head = out[i];
        out[i] = 0x3f3f3f3f;
      }
    }
    sum += Move[p];
  }
  for (int p = outside; p < Request; p++) {
    for (int i = 0; i < inside; i++) {
      temp[i] = abs(in[i] - Track_head);
    }
    for (int i = 0; i < inside; i++) {
      int d = 0;
      for (int j = 0; j < inside; j++) {
        if (temp[i] <= temp[j]) {
          d++;
        }
      }
      if (d == inside) {
        cout << "  " << in[i] << "\t\t\t";
        Move[p] = temp[i];
        cout << Move[p] << endl;
        Track_head = in[i];
        in[i] = 0x3f3f3f3f;
      }
    }
    sum += Move[p];
  }
  cout << "平均寻道长度:" << static_cast<double>(sum) / Request << endl;
  cout << endl;
}

void CSCAN(unordered_map<int, int> Track, int Track_head, int Request) {
  cout << "磁道起始位置:" << Track_head << endl;
  cout << "被访问的下一个磁道号"
       << "\t"
       << "移动距离" << endl;
  //当前磁道号里外数目,磁道号里外的磁道
  //判断当前磁道号里外的数目
  int inside = 0, outside = 0, in[Request], out[Request], tmp = 0;
  int temp[Request], sum = 0;
  for (int i = 0; i < Request; i++) {
    if (Track[i] >= Track_head) {
      out[outside++] = Track[i];
    } else {
      in[inside++] = Track[i];
    }
  }
  for (int p = 0; p < outside; p++) {
    for (int i = 0; i < outside; i++) {
      temp[i] = abs(out[i] - Track_head);
    }
    for (int i = 0; i < outside; i++) {
      int d = 0;
      for (int j = 0; j < outside; j++) {
        if (temp[i] <= temp[j]) {
          d++;
        }
      }
      if (d == outside) {
        cout << "  " << out[i] << "\t\t\t";
        Move[p] = temp[i];
        cout << Move[i] << endl;
        Track_head = out[i];
        out[i] = 0x3f3f3f3f;
      }
    }
    sum += Move[p];
  }
  for (int p = outside; p < Request; p++) {
    for (int i = 0; i < inside; i++) {
      temp[i] = in[i];
    }
    for (int i = 0; i < inside; i++) {
      int d = 0;
      for (int j = 0; j < inside; j++) {
        if (temp[i] <= temp[j]) {
          d++;
        }
      }
      if (d == inside) {
        cout << "  " << in[i] << "\t\t\t";
        Move[p] = abs(Track_head - temp[i]);
        cout << Move[p] << endl;
        Track_head = in[i];
        in[i] = 0x3f3f3f3f;
      }
    }
    sum += Move[p];
  }
  cout << "平均寻道长度:" << static_cast<double>(sum) / Request << endl;
  cout << endl;
}

int main() {
  cout << "----------------磁盘调度算法------------------" << endl;
  int Request; //请求数
  cout << "请输入请求数:";
  cin >> Request;
  srand((unsigned)time(nullptr));
  for (int i = 0; i < Request; i++) {
    Track1[i] = rand() % 201; //产生0~200之间的随机数
  }
  int Track_head; //磁道头,起始位置
  cout << "请输入磁道开始值:";
  cin >> Track_head;
  cout << endl;
  cout << "----------------FCFS磁盘调度算法----------------" << endl;
  FCFS(Track1, Track_head, Request);
  cout << "----------------SSTF磁盘调度算法----------------" << endl;
  S_STF(Track1, Track_head, Request);
  cout << "----------------SCAN磁盘调度算法----------------" << endl;
  SCAN(Track1, Track_head, Request);
  cout << "----------------CSCAN磁盘调度算法---------------" << endl;
  CSCAN(Track1, Track_head, Request);
  cout << "\n感谢使用，祝您生活愉快！" << endl;
  return 0;
}