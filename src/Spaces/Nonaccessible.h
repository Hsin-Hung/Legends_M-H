#ifndef _NON_ACCESS_H_
#define _NON_ACCESS_H_
#include "Spaces/Space.h"

class Nonaccessible : public Space
{

public:
    Nonaccessible();
    virtual ~Nonaccessible() = default;
    virtual void triggerEvent(std::unique_ptr<Hero> &hero) override;
    void display(std::ostream &os) const override;
    virtual std::string getSymbol() const override;
};

#endif