#ifndef _EXOSKELETON_H_
#define _EXOSKELETON_H_

#include "Monster.h"

class Exoskeleton : public Monster
{
public:
    Exoskeleton(std::string name, int level, int damage, int defense, int dodge);
    virtual void display(std::ostream &os) const override;
    virtual ~Exoskeleton() = default;
};

#endif