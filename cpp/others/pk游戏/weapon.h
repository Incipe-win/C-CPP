#ifndef WEAPON_H_

#define WEAPON_H_

#include <iostream>
#include <string>
using namespace std;

class Weapon {
public:
  virtual int getBaseDamage() = 0;
  virtual int getSuckBlood() = 0;
  virtual bool getHold() = 0;
  virtual bool getCrit() = 0;
  string weaponName;
  int baseDamage;
};

#endif // WEAPON_H_