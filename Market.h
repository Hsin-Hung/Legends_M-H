#ifndef _MARKET_H_
#define _MARKET_H_

#include "Space.h"
#include "Item.h"
#include "Attributes.h"
#include <vector>
#include <memory>

class Market : public Space
{
private:
    static std::vector<std::pair<ItemType, std::string>> file_paths;
    std::vector<std::shared_ptr<Item>> items;
    int enterMarket(std::unique_ptr<Hero> &hero);

public:
    Market();
    virtual ~Market() = default;
    virtual void triggerEvent(std::unique_ptr<Hero> &hero) override;
    void display(std::ostream &os) const override;
};

#endif