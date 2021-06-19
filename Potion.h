#ifndef _POTION_H_
#define _POTION_H_

#include "Item.h"
#include "Attributes.h"

class Potion : public Item
{
private:
    Attribute attr_inc;
    Attribute attr_aff;

public:
    Potion();
};

#endif