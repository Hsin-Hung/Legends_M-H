#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "Hero.h"

class Warrior : public Hero
{

public:
    Warrior(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp);
    virtual void display(std::ostream &os) const override;
    virtual ~Warrior() = default;
    virtual void subStatsUp(double percentage);
};

#endif