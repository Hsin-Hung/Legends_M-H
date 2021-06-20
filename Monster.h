#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Character.h"

class Monster : public Character
{
public:
    Monster(std::string name, int level, int damage, int defense, int dodge);
    virtual void display(std::ostream &os) const = 0;
    virtual ~Monster() = default;
};

#endif