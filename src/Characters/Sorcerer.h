#ifndef _SORCERER_H_
#define _SORCERER_H_

#include "Characters/Hero.h"

class Sorcerer : public Hero
{

public:
    Sorcerer(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp);
    virtual void display(std::ostream &os) const override;
    virtual ~Sorcerer() = default;
    virtual void subStatsUp(double percentage) override;
};

#endif