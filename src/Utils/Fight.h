#ifndef _FIGHT_H_
#define _FIGHT_H_

#include <memory>
#include "Characters/Hero.h"
#include "Characters/Monster.h"

class Fight
{
private:
    std::unique_ptr<Hero> &hero;
    std::unique_ptr<Monster> &monster;

public:
    Fight(std::unique_ptr<Hero> &hero, std::unique_ptr<Monster> &monster);
    void initFight();
};

#endif