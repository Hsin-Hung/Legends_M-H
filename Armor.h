#ifndef _ARMOR_H_
#define _ARMOR_H_

#include "Item.h"
class Armor : public Item
{
private:
    int damage_reduction;

public:
    static void displayHeader();
    virtual void display(std::ostream &os) const override;
    Armor(std::string name, int cost, int required_lvl, int damage_reduction);
    virtual ~Armor() = default;
};

#endif