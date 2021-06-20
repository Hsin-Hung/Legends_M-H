#ifndef _POTION_H_
#define _POTION_H_

#include "Item.h"
#include "Attributes.h"

class Potion : public Item
{
private:
    int attr_inc;
    Attribute attr_aff;

public:
    static void displayHeader();
    static std::string attrAffToString(const Attribute attr);
    virtual void display(std::ostream &os) const override;
    Potion(std::string name, int cost, int required_lvl, int attr_inc, Attribute attr_aff);
    virtual ~Potion() = default;
};

#endif