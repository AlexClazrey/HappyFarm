#include "FarmToolPlant.h"
#include "FarmField.h"
#include "GameDriverSingleton.h"
#include "DialogUnitField.h"
#include "FarmItemSeed.h"
#include "FarmCommand.h"
#include "DebugHeader.h"

FarmToolPlant::FarmToolPlant()
{
}

FarmToolPlant::~FarmToolPlant()
{
}

std::string FarmToolPlant::getName() {
    return "Plant";
}
std::string FarmToolPlant::getDesc() {
    return "Plant new crop here.";
}
bool FarmToolPlant::available(FarmField* target) {
    return target->empty();
}
int FarmToolPlant::action(FarmField *target) {
    // TODO scan items in backpack and make callbacks
    std::vector<FarmItem*> items = GameDriverSingleton::getInstance()->getFarm()->pack.scanPack();
    DialogUnitDesc::OptionsMsg res;
    res.cancelCBF = nullptr;
    res.title = "Plant Actions";
    res.emptyMsg = "<No Seeds>";
    res.select = 0;
    res.focusBackTo = DialogUnitField::FOCUS_NAME;
    res.focusBackMsg = nullptr;
    for(FarmItem *pItem : items) {
        if(pItem->getType() == FarmItem::Type::SEED) {
            #ifdef DEBUG_PLANT
            //GameDriverSingleton::getInstance()->addLog(std::to_string((long)pItem));
            GameDriverSingleton::getInstance()->addLog(pItem->getName() + " " + std::to_string(pItem->getCount()));
            //GameDriverSingleton::getInstance()->addLog(std::to_string(((FarmItemSeed*)pItem)->getSpecies()));
            #endif // DEBUG_PLANT
            res.options.push_back(MenuOption(pItem->getName(),
                                             pItem->getDesc(),
                                             std::bind(&FarmToolPlant::plant,
                                                       this,
                                                       target,
                                                       ((FarmItemSeed*)pItem)->getSpecies(),
                                                       pItem->getCode(),
                                                       pItem->getName())
                                             )
                                  );
        }
    }
    if(res.options.size() > 0) {
        res.addCancel = true;
    } else {
        res.addCancel = false;
        GameDriverSingleton::getInstance()->addLog("Empty hands with no seeds, I should go to the shop to buy some.");
    }
    GameDriverSingleton::getInstance()->toMenuPage(&res);
    return 2;
}

int FarmToolPlant::plant(FarmField *target, PlantSpecies::Code plantCode, FarmItem::Code seedCode, const std::string& plantName) {
    GameDriverSingleton::getInstance()->addLog("You plant " + plantName + " seed at field #" + std::to_string(target->getIdPlusOne()));
    FarmCommandPlant cmd = FarmCommandPlant(target, plantCode, seedCode);
    GameDriverSingleton::getInstance()->commitFarmCommand(&cmd);
    return 0;
}
