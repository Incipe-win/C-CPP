#ifndef MONSTER_H_
#define MONSTER_H_

#include "hero.h"
#include <iostream>
#include <string>
class Hero;

using namespace std;

class Monster {
public:
  Monster();
  string name;
  int hp;
  int atk;
  int def;
  bool isHold;

  void attack(Hero *hero);
};

#endif // MONSTER_H_