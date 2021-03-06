#ifndef _MARKET_H_
#define _MARKET_H_

#include "Spaces/Space.h"
#include "Items/Item.h"
#include "Characters/Attributes.h"
#include <vector>
#include <memory>

struct ItemTemplate
{

    ItemType type;
    std::string name;
    int cost;
    int required_lvl;
    int damage;
    int damage_reduced;
    int attr_inc;
    Attribute attr_aff;
    ItemTemplate(ItemType type, std::string name, int cost, int required_lvl, int damage, int damage_reduced, int attr_inc, Attribute attr_aff);
};

class Market : public Space
{
private:
    static std::vector<std::pair<ItemType, std::string>> file_paths;
    std::vector<std::unique_ptr<Item>> items;
    std::vector<ItemTemplate> item_templates;
    void enterMarket(std::unique_ptr<Hero> &hero);

public:
    Market();
    virtual ~Market() = default;
    virtual void triggerEvent(std::unique_ptr<Hero> &hero) override;
    void display(std::ostream &os) const override;
    virtual std::string getSymbol() const override;
};

#endif