#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>
#include "Utils/Displayable.h"

class Character : public Displayable
{
protected:
    std::string name;
    int level;
    int health;
    int damage;
    int defense;
    int dodge;

public:
    Character(std::string name, int level = 1, int damage = 0, int defense = 0, int dodge = 0);
    virtual ~Character() = default;

    virtual void display(std::ostream &os) const = 0;
    virtual void displayInfo() = 0;
    virtual void takeDamage(int dmg) = 0;
    virtual void mainStatsUp(double percentage) = 0;
    virtual void subStatsUp(double percentage) = 0;
    int getHealth() const;
    void gainDamage(int amount);
    void gainDamageReduction(int amount);
    void gainHealth(int amount);
    void reduceHealth(int dmg);
    bool isAlive() const;
    int getLevel() const;
};

#endif