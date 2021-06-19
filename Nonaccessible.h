#ifndef _NON_ACCESS_H_
#define _NON_ACCESS_H_
#include "Space.h"

class Nonaccessible : public Space
{

public:
    Nonaccessible();
    virtual void triggerEvent() override;
    void display(std::ostream &os) const override;
};

#endif