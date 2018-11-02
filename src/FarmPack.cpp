#include "FarmPack.h"
#include "PlantSpecies.h"
#include "FarmItemSeed.h"

FarmPack FarmPack::protoPack = FarmPack();
bool FarmPack::inited = false;

FarmPack::FarmPack()
{
    FarmPack::initProto();
}
FarmPack::~FarmPack()
{
    for(FarmItem* pItem : this->items) {
        delete pItem;
    }
}

std::vector<FarmItem*> FarmPack::scanPack() {
    std::vector<FarmItem*> res;
    for(int i = 0; i < getSize(); i++) {
        if(items[i] && items[i]->getCount() > 0) {
            res.push_back(items[i]);
        }
    }
    return res;
}

std::vector<FarmItem*> FarmPack::scanPack(const std::function<bool(const FarmItem*)>& judge) {
    std::vector<FarmItem*> res;
    for(int i = 0; i < getSize(); i++) {
        if(items[i] && judge(items[i])) {
            res.push_back(items[i]);
        }
    }
    return res;
}

void FarmPack::initProto() {
    if(!inited) {
    // TODO set FarmItem data here
        protoPack.items[FarmItem::Code::POTATO_SEED]
            = new FarmItemSeed(FarmItem::Code::POTATO_SEED,
                            "Potato Seeds",
                            "Little seeds from potato flowers.",
                            50,
                            20,
                            PlantSpecies::POTATO);
        protoPack.items[FarmItem::Code::POTATO_FRUIT]
            = new FarmItem(FarmItem::Type::FRUIT,
                    FarmItem::Code::POTATO_FRUIT,
                    "Potato",
                    "Finally, I dug out a big one.",
                    -1, 200);
    }
    inited = true;
}


