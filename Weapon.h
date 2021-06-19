#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"

class Weapon : public Item
{
private:
    int damage;
    int required_hand;

public:
    Weapon();
};

#endif