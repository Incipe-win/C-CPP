#include "hero.h"
#include "monster.h"
#include <iostream>
#include <string>

using namespace std;

Hero::Hero() {
  this->hp = 500;
  this->atk = 50;
  this->def = 50;
  this->name = "刘法师";
  this->weapon = nullptr;
}

void Hero::equipWeapon(Weapon *weapon) {
  this->weapon = weapon;
  cout << "Hero: " << this->name << "'s weapon is" << this->weapon->weaponName
       << endl;
}

void Hero::attck(Monster *monster) {
  int damage = 0;
  int addHp = 0;
  bool isHold = false;
  bool isCrit = false;
  if (this->weapon == nullptr) {
    damage = this->atk;
  } else {
    damage = this->atk + this->weapon->getBaseDamage();
    addHp = this->weapon->getSuckBlood();
    isHold = this->weapon->getHold();
    isCrit = this->weapon->getCrit();
  }
  if (isCrit) {
    damage = damage * 2;
    cout << "Crit is success, and it's result double damage!" << endl;
  }
  if (isHold) {
    cout << "Hold is success!" << endl;
  }
  if (addHp > 0) {
    cout << "addHp is success, and it's hp increase: " << addHp << endl;
  }
  monster->isHold = isHold;

  int trueDamage = (damage - monster->def > 0) ? damage - monster->def : 1;

  monster->hp -= trueDamage;
  this->hp += addHp;
  cout << "Hero" << this->name << "attack" << monster->name << ", and result "
       << trueDamage << "harm" << endl;
}