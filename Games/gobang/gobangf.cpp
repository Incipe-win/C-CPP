#include "gobang.h"
#include <bits/stdc++.h>

using namespace std;

Gobang::Gobang() { InitChessBoard(); }

void Gobang::InitChessBoard() {
  for (int i = 0; i < N + 1; ++i) {
    for (int j = 0; j < N + 1; ++j) {
      _ChessBoard[i][j] = ' ';
    }
  }
}

void Gobang::Play() {
  Position Play1; //玩家1或电脑
  Position Play2; //玩家2
  while (1) {
    int mode = ChoiceMode();
    while (1) {
      if (mode == 1) {               //电脑VS玩家
        ComputerChess(Play1, flag1); //电脑走
        if (GetVictory(Play1, 0, flag1)) { // 0代表电脑，为真则表示电脑获胜
          break;
        }
        PlayChess(Play2, 2, flag2);        //玩家2走
        if (GetVictory(Play2, 2, flag2)) { // 2代表玩家2
          break;
        }
      } else {                             //玩家1VS玩家2
        PlayChess(Play1, 1, flag1);        //玩家1走
        if (GetVictory(Play1, 1, flag1)) { //玩家1赢
          break;
        }
        PlayChess(Play2, 2, flag2);        //玩家2走
        if (GetVictory(Play2, 2, flag2)) { //玩家2赢
          break;
        }
      }
    }
    cout << "++++++play again?++++++" << endl;
    cout << "yes or no:";
    char s[] = "yes";
    cin >> s;
    if (strcmp(s, "no") == 0) {
      break;
    }
  }
}

int Gobang::ChoiceMode() {
  system("cls");
  InitChessBoard();
  cout << "-------------------------------------------" << endl;
  cout << "-----------------0:quit--------------------" << endl;
  cout << "----------1:Computer Vs people-------------" << endl;
  cout << "----------2:Computer Vs Computer-----------" << endl;
  while (1) {
    int i = 0;
    cout << "Please select mode:";
    cin >> i;
    if (i == 0) {
      exit(1);
    }
    if (i == 1 || i == 2) {
      return i;
    } else {
      cout << "Please input again!" << endl;
    }
  }
}

void Gobang::PrintChessBoard() {
  printf("     1   2   3   4   5   6   7   8   9  10  11  12  13  14  15\n");
  printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
  for (int i = 1; i < N + 1; ++i) {
    printf("%2d ", i);
    printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | "
           "%c | %c |\n",
           _ChessBoard[i][1], _ChessBoard[i][2], _ChessBoard[i][3],
           _ChessBoard[i][4], _ChessBoard[i][5], _ChessBoard[i][6],
           _ChessBoard[i][7], _ChessBoard[i][8], _ChessBoard[i][9],
           _ChessBoard[i][10], _ChessBoard[i][11], _ChessBoard[i][12],
           _ChessBoard[i][13], _ChessBoard[i][14], _ChessBoard[i][15]);
    printf(
        "   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
  }
  cout << endl;
}

void Gobang::ComputerChess(Position &pos, char flag) {
  int x = 0;
  int y = 0;
  while (1) {
    x = (rand() % N) + 1;
    srand((unsigned int)time(NULL));
    y = (rand() % N) + 1;
    srand((unsigned int)time(NULL));
    if (_ChessBoard[x][y] == ' ') {
      break;
    }
  }
  pos.row = x;
  pos.col = y;
  _ChessBoard[pos.row][pos.col] = flag;
}

void Gobang::PlayChess(Position &pos, int player, char flag) {
  PrintChessBoard();
  while (1) {
    cout << "Please player " << player << " input coordinate:";
    cin >> pos.row >> pos.col;
    if (JudgeValue(pos) == 1) {
      break;
    }
    cout << "The coordinates are not valid. Please reenter them" << endl;
  }
  _ChessBoard[pos.row][pos.col] = flag;
}

int Gobang::JudgeValue(const Position &pos) {
  if (pos.row > 0 && pos.row <= N && pos.col > 0 && pos.col <= N) {
    if (_ChessBoard[pos.row][pos.col] == ' ') {
      return 1;
    }
  }
  return 0;
}

int Gobang::JudgeVictory(Position pos, char flag) {
  int begin = 0;
  int end = 0;

  (pos.col - 4) > 0 ? begin = (pos.col - 4) : begin = 1;
  (pos.col + 4) > N ? end = N : end = (pos.col + 4);
  for (int i = pos.row, j = begin; j + 4 <= end; ++j) {
    if (_ChessBoard[i][j] == flag && _ChessBoard[i][j + 1] == flag &&
        _ChessBoard[i][j + 2] == flag && _ChessBoard[i][j + 3] == flag &&
        _ChessBoard[i][j + 4] == flag)
      return 1;
  }

  (pos.row - 4) > 0 ? begin = (pos.row - 4) : begin = 1;
  (pos.row + 4) > N ? end = N : end = (pos.row + 4);
  for (int j = pos.col, i = begin; i + 4 <= end; ++i) {
    if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j] == flag &&
        _ChessBoard[i + 2][j] == flag && _ChessBoard[i + 3][j] == flag &&
        _ChessBoard[i + 4][j] == flag)
      return 1;
  }

  int len = 0; //相对长度
  int start = 0;
  int finish = 0;
  pos.row > pos.col ? len = pos.col - 1 : len = pos.row - 1;
  if (len > 4) {
    len = 4;
  }
  begin = pos.row - len; //横坐标起始位置
  start = pos.col - len; //纵坐标起始位置

  pos.row > pos.col ? len = N - pos.row : len = N - pos.col;
  if (len > 4) {
    len = 4;
  }
  end = pos.row + len;    //横坐标结束位置
  finish = pos.col + len; //纵坐标结束位置

  for (int i = begin, j = start; (i + 4 <= end) && (j + 4 <= finish);
       ++i, ++j) {
    if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j + 1] == flag &&
        _ChessBoard[i + 2][j + 2] == flag &&
        _ChessBoard[i + 3][j + 3] == flag && _ChessBoard[i + 4][j + 4] == flag)
      return 1;
  }

  (pos.row - 1) > (N - pos.col) ? len = N - pos.col : len = pos.row - 1;
  if (len > 4) {
    len = 4;
  }
  begin = pos.row - len; //横坐标起始位置
  start = pos.col + len; //纵坐标起始位置

  (N - pos.row) > (pos.col - 1) ? len = pos.col - 1 : len = N - pos.row;
  if (len > 4) {
    len = 4;
  }
  end = pos.row + len;    //横坐标结束位置
  finish = pos.col - len; //纵坐标结束位置
  for (int i = begin, j = start; (i + 4 <= end) && (j - 4 >= finish);
       ++i, --j) {
    if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j - 1] == flag &&
        _ChessBoard[i + 2][j - 2] == flag &&
        _ChessBoard[i + 3][j - 3] == flag && _ChessBoard[i + 4][j - 4] == flag)
      return 1;
  }

  for (int x = 1; x < N + 1; ++x) {
    for (int y = 1; y < N + 1; ++y) {
      if (_ChessBoard[x][y] == ' ') {
        return 0; //未下棋
      }
    }
  }
  return -1;
}

bool Gobang::GetVictory(Position &pos, int player, char flag) {
  if (JudgeVictory(pos, flag) != 0) {   //判断有无人获胜
    if (JudgeVictory(pos, flag) == 1) { //判断是否有人获胜,1表示获胜
      PrintChessBoard();                //打印棋盘
      if (player == 0) {
        cout << "computer win!" << endl;
      } else {
        cout << "congratulation player " << player << "win" << endl;
      }
    } else {
      cout << "draw" << endl;
    }
    return true; //有人获胜
  }
  return false; //没人获胜
}

Gobang::~Gobang() {}