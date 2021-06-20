#ifndef _COMMON_H_
#define _COMMON_H_

#include "Space.h"

class Common : public Space
{

public:
    Common();
    virtual void triggerEvent(std::unique_ptr<Hero> &hero) override;
    void display(std::ostream &os) const override;
    virtual ~Common() = default;
};

#endif