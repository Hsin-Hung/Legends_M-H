#include "Characters/Hero.h"
#include "Characters/Monster.h"
#include "Utils/ColoredText.h"
#include "Utils/InputUtil.h"
#include <memory>
#include <iostream>
#include <iomanip>

Hero::Hero(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp)
    : Character(name), mana{mana}, strength{strength}, agility{agility}, dexterity{dexterity}, exp{exp}, inventory(money), weaponInUse{-1} {}

bool Hero::buyItem(std::unique_ptr<Item> item)
{
    if (item->getRequiredLvl() <= level && spend(item->getCost()))
    {
        std::cout << "\nYou have successfully bought " << ColoredText::yellow(item->getName()) << std::endl;
        if (item->getType() == Armor_T)
            item->useItem(*this);
        inventory.addItem(std::move(item));
        return true;
    }
    std::cout << ColoredText::red("\nItem purchase failed !") << std::endl;
    return false;
}
bool Hero::spend(int amount)
{
    return inventory.spend(amount);
}

void Hero::displayStats() const
{
    std::cout << std::endl;
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
    std::cout << std::string(170, '_') << std::endl;

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
    std::cout << std::endl;
}

void Hero::displayInventory() const
{

    inventory.display();
}

void Hero::displayInfo()
{
    int choice{-1};
    while (1)
    {
        do
        {
            std::cout << "\nView 1.Stats 2.Inventory 3.Use Weapon 4.Use Potion 5.Exit (enter ID):";
            std::cin >> choice;

            InputUtil::resetCin(std::cin, choice);

        } while (choice < 1 || choice > 5);

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
    if (!inventory.displayWeapon())
        return;

    int choice{-1};

    do
    {
        std::cout << "\nUse a weapon (enter ID): " << std::endl;
        std::cin >> choice;
        InputUtil::resetCin(std::cin, choice);
    } while (!inventory.isValidIndex(choice) || inventory.getItem(choice)->getType() != Weapon_T);

    damage = 0;
    weaponInUse = choice;
    inventory.getItem(weaponInUse)->useItem(*this);
}

void Hero::usePotion()
{
    if (!inventory.displayPotion())
        return;
    int choice{-1};

    do
    {

        std::cout << "\nUse a potion (enter ID): " << std::endl;
        std::cin >> choice;
        InputUtil::resetCin(std::cin, choice);

    } while (!inventory.isValidIndex(choice) || inventory.getItem(choice)->getType() != Potion_T);

    inventory.getItem(choice)->useItem(*this);
    inventory.removeItem(choice);
}

void Hero::gainStrength(int amount) { strength += amount; }
void Hero::gainAgility(int amount) { agility += amount; }
void Hero::gainDexterity(int amount) { dexterity += amount; }
void Hero::gainMana(int amount)
{

    mana = std::min(amount + mana, level * 100);
}

void Hero::startTurn(std::unique_ptr<Monster> &opp)
{
    int choice{0};
    std::cout << ColoredText::green("       YOUR TURN!\n") << std::endl;
    while (1)
    {
        do
        {
            std::cout << "\n1.Attack 2.Use Weapon 3.Use Potion 4. Inventory (enter ID):";
            std::cin >> choice;
            InputUtil::resetCin(std::cin, choice);

        } while (choice < 1 || choice > 4);

        switch (choice)
        {

        case 1:
        {
            std::cout << std::endl;
            std::cout << ColoredText::green(name) << " is attacking " << *opp << std::endl;
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
        std::cout << std::endl;
        std::cout << ColoredText::green(name) << " took " << ColoredText::red(std::to_string(dmg - (defense * 0.1))) << " damage!\n"
                  << std::endl;
        reduceHealth(dmg - (defense * 0.1));
    }
    else
    {
        std::cout << ColoredText::yellow("\nYou have dodged the attack!\n") << std::endl;
    }
}
void Hero::mainStatsUp(double percentage)
{
    gainHealth(health * percentage);
    gainMana(mana * percentage);
}

void Hero::winFight(std::unique_ptr<Monster> &opp)
{
    std::cout << std::endl;
    std::cout << ColoredText::green(name) << " wins the fight!\n"
              << std::endl;
    std::cout << "\nYou have gain " << opp->getLevel() * 100 << " coins!\n"
              << std::endl;
    inventory.earn(opp->getLevel() * 100);
    gainExp(2);
}

void Hero::gainExp(int amount)
{
    exp += amount;
    if (exp >= level * 10)
    {
        std::cout << ColoredText::green(name) << " leveled up!" << std::endl;
        ++level;
        health = 100 * level;
        mana = 100 * level;
        subStatsUp(0.05);
    }
}

void Hero::lostFight()
{

    health = level * 90;
    mana = level * 90;
    spend(20 * level);
}
