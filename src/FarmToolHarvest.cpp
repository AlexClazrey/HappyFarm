#include "FarmToolHarvest.h"
#include "FarmField.h"
#include "GameDriverSingleton.h"
#include "PlantLive.h"
#include "PlantState.h"
#include "FarmCommand.h"

FarmToolHarvest::FarmToolHarvest()
{
    name = "Harvest";
    desc = "Go and get them!";
}

FarmToolHarvest::~FarmToolHarvest()
{
}

bool FarmToolHarvest::available(FarmField* target) {
    return target->empty() ? false : target->getPlant()->getState()->mature;
}

int FarmToolHarvest::action(FarmField* target) {
    FarmCommandHarvest cmd(target);
    GameDriverSingleton::getInstance()->commitFarmCommand(&cmd);
    GameDriverSingleton::getInstance()->addLog("You harvested something on land #" + std::to_string(target->getIdPlusOne()) + ".");
    return 0;
}
