#ifndef _HERO_H_
#define _HERO_H_

#include "Character.h"
#include "Item.h"

class Hero : public Character
{   
    
    int mana;
    int strength;
    int agility;
    int dexterity;
    int money;
    int exp;

public:
    Hero(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp);
    virtual void display(std::ostream &os) const = 0;
    virtual ~Hero() = default;
    bool buyItem(std::shared_ptr<Item>&);
};

#endif