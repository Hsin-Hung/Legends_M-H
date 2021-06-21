#ifndef _ARMOR_H_
#define _ARMOR_H_

#include "Items/Item.h"

class Armor : public Item
{
private:
    int damage_reduction;

public:
    static void displayHeader();

    Armor(std::string name, int cost, int required_lvl, int damage_reduction);
    virtual ~Armor() = default;

    virtual void display(std::ostream &os) const override;
    virtual void useItem(Hero &hero) const override;
};

#endif