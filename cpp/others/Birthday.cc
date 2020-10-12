#include <windows.h>
using namespace std;

//定义低音
const int A1 = 131;
const int A2 = 147;
const int A3 = 165;
const int A4 = 175;
const int A5 = 196;
const int A6 = 220;
const int A7 = 247;

//定义中音
const int B1 = 262;
const int B2 = 296;
const int B3 = 330;
const int B4 = 349;
const int B5 = 392;
const int B6 = 440;
const int B7 = 494;

//定义高音
const int C1 = 523;
const int C2 = 587;
const int C3 = 659;
const int C4 = 698;
const int C5 = 784;
const int C6 = 880;
const int C7 = 988;

//定义高二度
const int D1 = 1047;
const int D2 = 1175;
const int D3 = 1319;
const int D4 = 1397;
const int D5 = 1568;
const int D6 = 1760;
const int D7 = 1976;

//定义节拍
const int OneBeat = 600;
const int HalfBeat = 300;

int main() {
  int T = 3;
  while (T--) {
    Beep(C5, HalfBeat);
    Beep(C5, HalfBeat);
    Beep(C6, OneBeat);
    Beep(C5, OneBeat);
    Beep(D1, OneBeat);
    Beep(C7, OneBeat * 2);

    Beep(C5, HalfBeat);
    Beep(C5, HalfBeat);
    Beep(C6, OneBeat);
    Beep(C5, OneBeat);
    Beep(D2, OneBeat);
    Beep(D1, OneBeat * 2);

    Beep(C5, HalfBeat);
    Beep(C5, HalfBeat);
    Beep(D5, OneBeat);
    Beep(D3, OneBeat);
    Beep(D1, OneBeat);
    Beep(C7, OneBeat);

    Beep(D4, HalfBeat);
    Beep(D4, HalfBeat);
    Beep(D3, OneBeat);
    Beep(D1, OneBeat);
    Beep(D2, OneBeat);
    Beep(D1, OneBeat * 2);

    Beep(C5, HalfBeat);
    Beep(C5, HalfBeat);
    Beep(D5, OneBeat);
    Beep(D3, OneBeat);
    Beep(D1, OneBeat);
    Beep(C7, HalfBeat);
    Beep(C6, OneBeat * 2);

    Beep(D4, HalfBeat);
    Beep(D4, HalfBeat);
    Beep(D3, OneBeat);
    Beep(D1, OneBeat);
    Beep(D2, OneBeat);
    Beep(D1, OneBeat * 3);

    Sleep(500);
  }
  return 0;
}