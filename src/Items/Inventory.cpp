#include "Items/Inventory.h"
#include "Utils/ColoredText.h"
#include "Utils/InputUtil.h"
#include <iomanip>

Inventory::Inventory(int money) : money{money}
{
}

void Inventory::addItem(std::unique_ptr<Item> item)
{

    items.push_back(std::move(item));
}
std::unique_ptr<Item> &Inventory::getItem(size_t i)
{

    return items[i];
}

bool Inventory::isValidIndex(int i) const
{

    return i >= 0 && (size_t)i < items.size();
}

void Inventory::removeItem(size_t i)
{
    items.erase(items.begin() + i);
}
bool Inventory::spend(int amount)
{
    if (money >= amount)
    {
        money -= amount;
        return true;
    }
    std::cout << ColoredText::red("\nYou don't have enought balance!") << std::endl;
    return false;
}
void Inventory::earn(int amount)
{
    money += amount;
}
int Inventory::getMoney() const
{
    return money;
}

void Inventory::display() const
{

    while (1)
    {
        std::cout << "\nYou have $" + ColoredText::yellow(std::to_string(money)) << std::endl;
        std::cout << std::endl;
        int choice{-1};
        do
        {
            std::cout << "\nView 1.Armory 2.Weaponry 3.Potion 4.Exit (enter number): ";
            std::cin >> choice;
            InputUtil::resetCin(std::cin, choice);
        } while (choice < 1 || choice > 4);

        if (choice == 4)
            return;

        ItemType choiceType{static_cast<ItemType>(choice)};
        if (choiceType == Armor_T)
        {
            displayArmor();
        }
        else if (choiceType == Weapon_T)
        {
            displayWeapon();
        }
        else if (choiceType == Potion_T)
        {
            displayPotion();
        }
    }
}

bool Inventory::displayArmor() const
{

    bool exist{false};
    Armor::displayHeader();
    for (auto i{0}; i < items.size(); i++)
    {
        if (items[i]->getType() == Armor_T)
        {
            std::cout << std::setw(5) << std::left << i;
            std::cout << *items[i];
            exist = true;
        }
    }

    return exist;
}
bool Inventory::displayWeapon() const
{

    bool exist{false};
    Weapon::displayHeader();
    for (auto i{0}; i < items.size(); i++)
    {
        if (items[i]->getType() == Weapon_T)
        {
            std::cout << std::setw(5) << std::left << i;
            std::cout << *items[i];
            exist = true;
        }
    }

    return exist;
}
bool Inventory::displayPotion() const
{

    bool exist{false};
    Potion::displayHeader();
    for (auto i{0}; i < items.size(); i++)
    {
        if (items[i]->getType() == Potion_T)
        {
            std::cout << std::setw(5) << std::left << i;
            std::cout << *items[i];
            exist = true;
        }
    }

    return exist;
}