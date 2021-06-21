#include "Inventory.h"
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
    std::cout << "You don't have enought balance!" << std::endl;
    return false;
}
void Inventory::earn(int amount)
{
    money += amount;
}
int Inventory::getMoney()
{
    return money;
}

void Inventory::display() const
{

    while (1)
    {
        std::cout << "You have $" << money << std::endl;
        int choice{-1};
        do
        {
            std::cout << "View 1.Armory 2.Weaponry 3.Potion 4.Exit (enter number): ";
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore();
        } while (std::cin.fail() || choice < 1 || choice > 4);

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

void Inventory::displayArmor() const
{

    Armor::displayHeader();
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->getType() == Armor_T)
        {
            std::cout << std::setw(5) << std::left << i;
            std::cout << *items[i];
        }
    }
}
void Inventory::displayWeapon() const
{

    Weapon::displayHeader();
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->getType() == Weapon_T)
        {
            std::cout << std::setw(5) << std::left << i;
            std::cout << *items[i];
        }
    }
}
void Inventory::displayPotion() const
{

    Potion::displayHeader();
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->getType() == Potion_T)
        {
            std::cout << std::setw(5) << std::left << i;
            std::cout << *items[i];
        }
    }
}