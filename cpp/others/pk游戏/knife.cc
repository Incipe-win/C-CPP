#include "knife.h"
#include <iostream>
#include <string>

using namespace std;

Knife::Knife() {
  this->baseDamage = 10;
  this->weaponName = "Knife";
}

int Knife::getBaseDamage() { return this->baseDamage; }

int Knife::getSuckBlood() { return 0; }

bool Knife::getHold() { return false; }

bool Knife::getCrit() { return false; }