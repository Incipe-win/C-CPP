#ifndef HERO_H_
#define HERO_H_
#include "monster.h"
#include "weapon.h"
#include <iostream>
#include <string>
class Monster;

using namespace std;
class Hero {
public:
  Hero();
  string name;
  int atk;
  int def;
  int hp;
  Weapon *weapon;
  void equipWeapon(Weapon *weapon);
  void attck(Monster *monster);
};

#endif // HERO_H_