#ifndef _SPIRIT_H_
#define _SPIRIT_H_

#include "Characters/Monster.h"

class Spirit : public Monster
{
public:
    Spirit(std::string name, int level, int damage, int defense, int dodge);
    virtual void display(std::ostream &os) const override;
    virtual ~Spirit() = default;
};

#endif