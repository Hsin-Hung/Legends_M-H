#ifndef _ARMOR_H_
#define _ARMOR_H_

#include "Item.h"
class Armor : public Item
{
private:
    int damage_reduction;

public:
    Armor();
};

#endif