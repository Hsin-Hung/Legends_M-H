#ifndef _HERO_H_
#define _HERO_H_

#include "Character.h"
#include "Item.h"
#include "Inventory.h"
#include <memory>

class Monster;

class Hero : public Character
{
protected:
    int mana;
    int strength;
    int agility;
    int dexterity;
    int exp;
    Inventory inventory;
    int weaponInUse;

public:
    Hero(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp);
    virtual void display(std::ostream &os) const = 0;
    virtual ~Hero() = default;
    virtual void mainStatsUp(double percentage);
    virtual void subStatsUp(double percentage) = 0;
    bool buyItem(std::unique_ptr<Item>);
    bool spend(int amount);
    void increaseDamage(int amount);
    void increaseDamageReduction(int amount);
    void increaseStrength(int amount);
    void increaseAgility(int amount);
    void increaseDexterity(int amount);
    void increaseExp(int amount);
    void increaseMana(int amount);
    void increaseHealth(int amount);
    virtual void displayInfo();
    void displayStats() const;
    void displayInventory() const;
    void pickWeapon();
    void usePotion();
    void startTurn(std::unique_ptr<Monster> &opp);
    virtual void takeDamage(int dmg);
    void winFight(std::unique_ptr<Monster> &opp);
    void gainExp(int amount);

};

#endif