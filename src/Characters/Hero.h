#ifndef _HERO_H_
#define _HERO_H_

#include "Characters/Character.h"
#include "Items/Item.h"
#include "Items/Inventory.h"
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
    virtual ~Hero() = default;

    virtual void display(std::ostream &os) const = 0;
    virtual void subStatsUp(double percentage) = 0;
    virtual void mainStatsUp(double percentage);
    virtual void displayInfo();
    virtual void takeDamage(int dmg);

    bool buyItem(std::unique_ptr<Item>);
    bool spend(int amount);
    void gainExp(int amount);
    void gainStrength(int amount);
    void gainAgility(int amount);
    void gainDexterity(int amount);
    void gainMana(int amount);
    void displayStats() const;
    void displayInventory() const;
    void pickWeapon();
    void usePotion();
    void startTurn(std::unique_ptr<Monster> &opp);
    void winFight(std::unique_ptr<Monster> &opp);
    void lostFight();
};

#endif