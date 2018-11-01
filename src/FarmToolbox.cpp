#include "FarmToolbox.h"
#include "FarmToolWater.h"
#include "FarmToolPlant.h"
#include "GameDriverSingleton.h"
#include "DebugHeader.h"
#include "FarmToolHarvest.h"
#include "FarmToolPesticide.h"

FarmToolbox::FarmToolbox()
{
    this->tools.push_back(new FarmToolWater());
    this->tools.push_back(new FarmToolPlant());
    this->tools.push_back(new FarmToolHarvest());
    this->tools.push_back(new FarmToolPesticide());
}

FarmToolbox::~FarmToolbox()
{
    for(auto tool : this->tools) {
        delete tool;
    }
    this->tools.clear();
}

void FarmToolbox::availableOptions(std::vector<MenuOption> &dest, FarmField* field) {
#ifdef TOOL_DEBUG
    GameDriverSingleton::getInstance()->addLog(std::string("Tool Count: ") + std::to_string(this->tools.size()));
    GameDriverSingleton::getInstance()->addLog(this->tools[0]->getName());
#endif
    for(auto tool : this->tools) {
        if(tool->available(field)) {
            dest.emplace_back(tool->getName(), tool->getDesc(), tool->getCallback(field));
        }
    }
}
