#ifndef _SPELL_H_
#define _SPELL_H_

#include "Item.h"

class Spell : public Item
{
private:
    int damage;
    int mana_cost;

public:
    Spell();
};

#endif