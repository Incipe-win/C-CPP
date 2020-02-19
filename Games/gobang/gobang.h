#ifndef _GOBANG_H_
#define _GOBANG_H_

#include <bits/stdc++.h>
using namespace std;

const int N = 15; // 15*15的棋盘
// const char ChessBoard = ' '; //棋盘标志
const char flag1 = 'o'; //玩家1或电脑标志
const char flag2 = 'x'; //玩家2标志

typedef struct Position {
  int row;
  int col;
} Position;

class Gobang {
public:
  Gobang();
  ~Gobang();
  void Play();

protected:
  void InitChessBoard();
  int ChoiceMode();
  void PrintChessBoard();
  void ComputerChess(Position &pos, char flag);
  void PlayChess(Position &pos, int player, char flag);
  int JudgeValue(const Position &pos);
  int JudgeVictory(Position pos, char flag);
  bool GetVictory(Position &pos, int player, char flag);

private:
  char _ChessBoard[N + 1][N + 1];
};

#endif //_GOBANG_H_