#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Items/Item.h"

class Weapon : public Item
{
private:
    int damage;

public:
    static void displayHeader();

    Weapon(std::string name, int cost, int required_lvl, int damage);
    virtual ~Weapon() = default;

    virtual void display(std::ostream &os) const override;
    virtual void useItem(Hero &hero) const override;
};

#endif