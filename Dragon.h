#ifndef _DRAGON_H_
#define _DRAGON_H_

#include "Monster.h"

class Dragon : public Monster
{
public:
    Dragon(std::string name, int level, int damage, int defense, int dodge);
    virtual void display(std::ostream &os) const override;
    virtual ~Dragon() = default;
};

#endif