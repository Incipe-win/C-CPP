#include "dragonSword.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

DragonSword::DragonSword() {
  this->baseDamage = 20;
  this->weaponName = "Dragon Kinfe";

  this->suckRate = 20;
  this->holdRate = 30;
  this->critRate = 35;
}

int DragonSword::getBaseDamage() { return this->baseDamage; }

int DragonSword::getSuckBlood() {
  if (isTrigger(suckRate)) {
    return this->baseDamage * 0.5;
  }
  return 0;
}

bool DragonSword::getHold() {
  if (isTrigger(holdRate)) {
    return true;
  }
  return false;
}

bool DragonSword::getCrit() {
  if (isTrigger(critRate)) {
    return true;
  }
  return false;
}

bool DragonSword::isTrigger(int rate) {
  int num = rand() % 100 + 1;
  if (num < rate) {
    return true;
  }
  return false;
}
