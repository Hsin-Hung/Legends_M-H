#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"

class Weapon : public Item
{
private:
    int damage;

public:
    static void displayHeader();
    virtual void display(std::ostream &os) const override;
    Weapon(std::string name, int cost, int required_lvl, int damage);
    virtual ~Weapon() = default;
    virtual void updateHero(Hero &hero) const override;
};

#endif