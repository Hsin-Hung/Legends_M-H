#ifndef _SPIRIT_H_
#define _SPIRIT_H_

#include "Monster.h"

class Spirit : public Monster
{
public:
    Spirit(std::string name, int level, int damage, int defense, int dodge);
    virtual void display(std::ostream &os) const;
    virtual ~Spirit() = default;
};

#endif