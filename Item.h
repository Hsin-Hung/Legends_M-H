
#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>
#include "Displayable.h"

class Hero;

enum ItemType
{
    Armor_T = 1,
    Weapon_T = 2,
    Potion_T = 3,

};

class Item : public Displayable
{

protected:
    ItemType type;
    std::string name;
    int cost;
    int required_lvl;

public:
    virtual void display(std::ostream &os) const = 0;
    Item(ItemType type, std::string name, int cost, int required_lvl);
    virtual ~Item() = default;
    ItemType getType();
    std::string getName();
    int getRequiredLvl();
    int getCost();
    virtual void updateHero(Hero &hero) const = 0;
};
#endif