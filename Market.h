#ifndef _MARKET_H_
#define _MARKET_H_

#include "Space.h"

class Market : public Space
{

public:
    Market();
    virtual ~Market() = default;
    virtual void triggerEvent() override;
    void display(std::ostream &os) const override;
};

#endif