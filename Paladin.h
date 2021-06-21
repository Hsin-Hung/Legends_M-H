#ifndef _PALADIN_H_
#define _PALADIN_H_

#include "Hero.h"

class Paladin : public Hero
{

public:
    Paladin(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp);
    virtual void display(std::ostream &os) const override;
    virtual ~Paladin() = default;
    virtual void subStatsUp(double percentage);
};

#endif