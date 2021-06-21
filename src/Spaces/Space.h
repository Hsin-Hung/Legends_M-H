#ifndef _SPACE_H_
#define _SPACE_H_

#include "Utils/Displayable.h"
#include "Characters/Hero.h"
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
    virtual ~Space() = default;

    virtual void triggerEvent(std::unique_ptr<Hero> &hero) = 0;
    virtual void display(std::ostream &os) const = 0;
    virtual std::string getSymbol() const = 0;
    SpaceType getType() const;
    bool isAccessible() const;
};

#endif