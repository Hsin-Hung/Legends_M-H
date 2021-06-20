#ifndef _HERO_H_
#define _HERO_H_

#include "Character.h"
#include "Item.h"
#include "Inventory.h"

class Hero : public Character
{

    int mana;
    int strength;
    int agility;
    int dexterity;
    int money;
    int exp;
    Inventory inventory;

public:
    Hero(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp);
    virtual void display(std::ostream &os) const = 0;
    virtual ~Hero() = default;
    bool buyItem(std::unique_ptr<Item>);
};

#endif