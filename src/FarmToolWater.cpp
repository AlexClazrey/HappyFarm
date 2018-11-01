#include "FarmToolWater.h"
#include "FarmField.h"
#include "GameDriverSingleton.h"

FarmToolWater::FarmToolWater()
{
    this->name = "Water";
    this->desc = "Water this land.";
    this->waterAmount = 30;
}

FarmToolWater::~FarmToolWater()
{
    //dtor
}

std::string FarmToolWater::getName() {
    return this->name;
}
std::string FarmToolWater::getDesc() {
    return this->desc;
}
bool FarmToolWater::available(FarmField* target) {
    return target->getWater() <= 0;
}
int FarmToolWater::action(FarmField *target) {
    // no need to use FarmCommand cause it's a simple action
    target->setWater(target->getWater() + this->waterAmount);
    GameDriverSingleton::getInstance()->addLog("You watered land #" + std::to_string(target->getIdPlusOne()) + ".");
    return 0;
}
