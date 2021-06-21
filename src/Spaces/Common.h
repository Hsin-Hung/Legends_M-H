#ifndef _COMMON_H_
#define _COMMON_H_

#include "Spaces/Space.h"

class Common : public Space
{
private:
    static double monsterEncounterChance;

public:
    Common();
    virtual ~Common() = default;
    virtual void triggerEvent(std::unique_ptr<Hero> &hero) override;
    void display(std::ostream &os) const override;
    virtual std::string getSymbol() const override;
};

#endif