#ifndef DRAGONSWORD_H_
#define DRAGONSWORD_H_

#include "weapon.h"
#include <iostream>
#include <string>

using namespace std;

class DragonSword : public Weapon {
public:
  DragonSword();
  virtual int getBaseDamage();
  virtual int getSuckBlood();
  virtual bool getHold();
  virtual bool getCrit();
  int suckRate;
  int holdRate;
  int critRate;

  bool isTrigger(int rate);
};

#endif // DRAGONSWORD_H_