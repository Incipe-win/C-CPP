#ifndef KNIFE_H_

#define KNIFE_H_

#include "weapon.h"
#include <iostream>
#include <string>

using namespace std;

class Knife : public Weapon {
public:
  Knife();
  virtual int getBaseDamage();
  virtual int getSuckBlood();
  virtual bool getHold();
  virtual bool getCrit();
};

#endif // KNIFE_H_