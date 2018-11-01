#include "FarmToolPesticide.h"
#include "FarmField.h"
#include "PlantLive.h"
#include "PlantState.h"
#include "GameDriverSingleton.h"

FarmToolPesticide::FarmToolPesticide()
{
    name = "Pesticide";
    desc = "I hate bugs, from old times to now...";
}

FarmToolPesticide::~FarmToolPesticide()
{
}

std::string FarmToolPesticide::getName() {
    return this->name;
}
std::string FarmToolPesticide::getDesc() {
    return this->desc;
}
bool FarmToolPesticide::available(FarmField* target) {
    return target->empty() ? false : target->getPlant()->getState()->worm;
}
int FarmToolPesticide::action(FarmField *target) {
    // no need to use FarmCommand cause it's a simple action
    target->getPlant()->getState()->worm = false;
    GameDriverSingleton::getInstance()->addLog("You sprinkled pesticide on land #" + std::to_string(target->getIdPlusOne()) + ".");
    return 0;
}
