#include "dragonSword.h"
#include "hero.h"
#include "knife.h"
#include "monster.h"
#include "weapon.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void play() {
  Monster *monster = new Monster;
  Hero *hero = new Hero;

  Weapon *knife = new Knife;
  Weapon *dragon = new DragonSword;
  cout << "please choose weapon:" << endl;
  cout << "0. nullptr" << endl;
  cout << "1. knife" << endl;
  cout << "2. dragonSword" << endl;
  int oper;
  cin >> oper;
  switch (oper) {
  case 0:
    cout << "your choose is nullptr" << endl;
    break;
  case 1:
    cout << "your choose is knife" << endl;
    hero->equipWeapon(knife);
    break;
  case 2:
    cout << "your choose is dragon" << endl;
    hero->equipWeapon(dragon);
    break;
  }
  getchar();
  int round = 1;
  while (true) {
    getchar();
    system("clear");
    cout << "round is :" << round << ", and game is begin!" << endl;
    if (hero->hp <= 0) {
      cout << "hero " << hero->name << " is die" << endl;
      break;
    }
    hero->attck(monster);
    if (monster->hp <= 0) {
      cout << "monster " << monster->name << " is die" << endl;
      cout << "you have win the game" << endl;
      break;
    }
    monster->attack(hero);
    if (hero->hp <= 0) {
      cout << "hero " << hero->name << " is die" << endl;
      break;
    }
    cout << "hero " << hero->name << "'s hp is " << hero->hp << endl;
    cout << "monster " << monster->name << "'s hp is " << monster->hp << endl;
    ++round;
  }
  delete hero;
  delete monster;
  delete dragon;
  delete knife;
}

int main() {
  srand((unsigned int)time(nullptr));
  play();
  return 0;
}