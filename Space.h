#ifndef _SPACE_H_
#define _SPACE_H_

#include "Displayable.h"
#include "Hero.h"
#include <memory>

enum SpaceType
{
    Common_T,
    Market_T,
    Inaccessible_T
};

class Space : public Displayable
{

private:
    SpaceType type;
    bool accessible;

public:
    Space(bool accessible, SpaceType type);
    virtual void triggerEvent(std::unique_ptr<Hero> &hero) = 0;
    virtual ~Space() = default;
    SpaceType getType();
    bool isAccessible();
};

#endif