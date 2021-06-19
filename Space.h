#ifndef _SPACE_H_
#define _SPACE_H_

#include "Displayable.h"

class Space: public Displayable
{

private:
    bool accessible;

public:
    Space(bool accessible) : accessible{accessible} {};
    virtual void triggerEvent() = 0;
    virtual ~Space() = default;
};

#endif