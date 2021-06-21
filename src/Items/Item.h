
#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>
#include "Utils/Displayable.h"

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
    Item(ItemType type, std::string name, int cost, int required_lvl);
    virtual ~Item() = default;
    virtual void display(std::ostream &os) const = 0;
    virtual void useItem(Hero &hero) const = 0;
    ItemType getType();
    std::string getName();
    int getCost();
    int getRequiredLvl();
};
#endif