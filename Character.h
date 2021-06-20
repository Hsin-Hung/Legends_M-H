#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>
#include "Displayable.h"

class Character : public Displayable
{
protected:
    std::string name;
    int level;
    int damage;
    int defense;
    int dodge;

public:
    Character(std::string name, int level, int damage, int defense, int dodge);
    virtual void display(std::ostream &os) const = 0;
    virtual ~Character() = default;
};

#endif