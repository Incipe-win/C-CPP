#include "monster.h"
#include "hero.h"
#include <iostream>
#include <string>

using namespace std;

Monster::Monster() {
  this->hp = 300;
  this->atk = 70;
  this->def = 40;
  this->isHold = false;
  this->name = "比克大魔王";
}

void Monster::attack(Hero *hero) {
  if (this->isHold) {
    cout << "Monster" << this->name << "is hold" << endl;
    return;
  }
  int damage = (this->atk - hero->def) > 0 ? this->atk - hero->def : 1;
  cout << "Monster" << this->name << "attack" << hero->name << ", and result "
       << damage << "harm" << endl;
}