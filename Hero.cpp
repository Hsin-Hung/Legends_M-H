#include "Hero.h"
#include "Monster.h"
#include <memory>
#include <iostream>
#include <iomanip>

Hero::Hero(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp)
    : Character(name), mana{mana}, strength{strength}, agility{agility}, dexterity{dexterity}, exp{exp}, inventory(money), weaponInUse{-1} {}

bool Hero::buyItem(std::unique_ptr<Item> item)
{
    if (item->getRequiredLvl() <= level && spend(item->getCost()))
    {
        std::cout << "You have successfully bought " << item->getName() << std::endl;
        if (item->getType() == Armor_T)
            item->updateHero(*this);
        inventory.addItem(std::move(item));
        return true;
    }
    std::cout << "Item purchase failed!" << std::endl;
    return false;
}
bool Hero::spend(int amount)
{
    return inventory.spend(amount);
}

void Hero::increaseDamage(int amount)
{
    damage += amount;
    if (damage < 0)
        damage = 0;
}
void Hero::increaseDamageReduction(int amount)
{
    defense += amount;
    if (defense < 0)
        defense = 0;
}

void Hero::displayStats() const
{

    std::cout << std::setw(25) << std::left << "Name";
    std::cout << std::setw(15) << std::left << "Level";
    std::cout << std::setw(15) << std::left << "Health";
    std::cout << std::setw(15) << std::left << "Mana";
    std::cout << std::setw(15) << std::left << "Strength";
    std::cout << std::setw(15) << std::left << "Agility";
    std::cout << std::setw(15) << std::left << "Dexterity";
    std::cout << std::setw(15) << std::left << "Exp";
    std::cout << std::setw(15) << std::left << "Damage";
    std::cout << std::setw(15) << std::left << "Defense";
    std::cout << std::setw(15) << std::left << "Dodge" << std::endl;
    std::cout << std::string(200, '_') << std::endl;

    std::cout << std::setw(25) << std::left << name;
    std::cout << std::setw(15) << std::left << level;
    std::cout << std::setw(15) << std::left << health;
    std::cout << std::setw(15) << std::left << mana;
    std::cout << std::setw(15) << std::left << strength;
    std::cout << std::setw(15) << std::left << agility;
    std::cout << std::setw(15) << std::left << dexterity;
    std::cout << std::setw(15) << std::left << exp;
    std::cout << std::setw(15) << std::left << damage;
    std::cout << std::setw(15) << std::left << defense;
    std::cout << std::setw(15) << std::left << dodge << std::endl;
}

void Hero::displayInventory() const
{

    inventory.display();
}

void Hero::displayInfo()
{
    int choice{};
    while (1)
    {
        do
        {
            std::cout << "View 1.Stats 2.Inventory 3.Use Weapon 4.Use Potion 5.Exit (enter ID):";
            std::cin >> choice;

        } while (std::cin.fail() || choice < 1 || choice > 5);

        switch (choice)
        {

        case 1:
            displayStats();
            break;
        case 2:
            displayInventory();
            break;
        case 3:
            pickWeapon();
            break;
        case 4:
            usePotion();
            break;
        case 5:
            return;
        default:
            break;
        }
    }
}

void Hero::pickWeapon()
{
    inventory.displayWeapon();
    int choice{-1};

    do
    {
        std::cout << "Use a weapon (enter ID): " << std::endl;
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore();
    } while (std::cin.fail());

    damage = 0;
    weaponInUse = choice;
    inventory.getItem(weaponInUse)->updateHero(*this);
}

void Hero::usePotion()
{
    inventory.displayPotion();
    int choice{-1};

    do
    {
        std::cout << "Use a potion (enter ID): " << std::endl;
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore();
    } while (std::cin.fail());

    inventory.getItem(choice)->updateHero(*this);
    inventory.removeItem(choice);
}

void Hero::increaseStrength(int amount) { strength += amount; }
void Hero::increaseAgility(int amount) { agility += amount; }
void Hero::increaseDexterity(int amount) { dexterity += amount; }
void Hero::increaseExp(int amount) { exp += amount; }
void Hero::increaseMana(int amount)
{

    mana += amount;
    if (mana > level * 100)
        mana = level * 100;
}
void Hero::increaseHealth(int amount) { health += amount; }

void Hero::startTurn(std::unique_ptr<Monster> &opp)
{
    int choice{0};
    std::cout << "Your turn!" << std::endl;
    while (1)
    {
        do
        {
            std::cout << "1.Attack 2.Use Weapon 3.Use Potion 4. Inventory (enter ID):";
            std::cin >> choice;

        } while (std::cin.fail() || choice < 1 || choice > 4);

        switch (choice)
        {

        case 1:
        {
            std::cout << name << " is attacking " << *opp << std::endl;
            int finalDmg{0};
            finalDmg = (strength + damage) * 0.05;
            opp->takeDamage(finalDmg);
            return;
        }

        case 2:
        {
            pickWeapon();
            return;
        }

        case 3:
        {
            usePotion();
            return;
        }

        case 4:
            displayInventory();
            break;
        default:
            break;
        }
    }
}

void Hero::takeDamage(int dmg)
{

    std::srand(std::time(nullptr));
    int random_num{};
    random_num = std::rand() % 100;

    if (random_num > agility * 0.002)
    {
        std::cout << name << " took " << dmg - (defense * 0.1) << "daamage!" << std::endl;
        reduceHealth(dmg - (defense * 0.1));
    }
    else
    {
        std::cout << "You have dodged the attack!" << std::endl;
    }
}
void Hero::mainStatsUp(double percentage)
{
    gainHealth(health * percentage);
    increaseMana(mana * percentage);
}

void Hero::winFight(std::unique_ptr<Monster> &opp)
{
    std::cout << name << " wins the fight!" << std::endl;
    std::cout << "You have gain " << opp->getLevel() * 100 << " coins!" << std::endl;
    inventory.earn(opp->getLevel() * 100);
    gainExp(2);
}

void Hero::gainExp(int amount)
{
    exp += amount;
    if (exp >= level * 10)
    {
        std::cout << name << " leveled up!" << std::endl;
        ++level;
        health = 100 * level;
        mana = 100 * level;
        subStatsUp(0.05);
    }
}
