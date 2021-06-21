#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Character.h"
#include "Hero.h"

class Monster : public Character
{
public:
    Monster(std::string name, int level, int damage, int defense, int dodge);
    virtual void display(std::ostream &os) const = 0;
    virtual void displayInfo();
    virtual ~Monster() = default;
    void startTurn(std::unique_ptr<Hero> &opp);
    virtual void takeDamage(int dmg);
    virtual void mainStatsUp(double percentage);
    virtual void subStatsUp(double percentage);
};

#endif