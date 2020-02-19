#include "public.h"
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
  cout << "-------------------Gluttonous Snake---------------------" << endl;
  cout << "Please enter two Numbers to indicate the size of the map" << endl;
  cout << " Enter a number 1-10. 1 is the easiest,10is the hardest " << endl;
  cout << "                   Have a good game!                    " << endl;
  int m, n, snakelen = 5;
  cout << "Please input the length and width of the wall:";
  cin >> m >> n;
  cout << "Please enter the hard of games:";
  Snake p(m, n, snakelen);
  for (int i = 0; i <= 4; i++) {
    snake[i].x = 1;
    snake[i].y = 5 - i;
  }
  system("cls");
  p.hide();
  p.print_wall();
  p.print_snake();
  system("pause");
  return 0;
}
