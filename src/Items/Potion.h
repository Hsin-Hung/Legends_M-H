#ifndef _POTION_H_
#define _POTION_H_

#include "Items/Item.h"
#include "Characters/Attributes.h"

class Potion : public Item
{
private:
    int attr_inc;
    Attribute attr_aff;

public:
    static void displayHeader();
    static std::string attrAffToString(const Attribute attr);

    Potion(std::string name, int cost, int required_lvl, int attr_inc, Attribute attr_aff);
    virtual ~Potion() = default;

    virtual void display(std::ostream &os) const override;
    virtual void useItem(Hero &hero) const override;
};

#endif