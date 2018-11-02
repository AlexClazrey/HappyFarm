#include "FarmField.h"
#include "PlantLive.h"
#include "PlantState.h"
#include "PlantSpecies.h"
#include "GameDriverSingleton.h"
#include <sstream>

FarmField::FarmField() : id(0), waterAmount(0), plant(nullptr)
{
}

FarmField::~FarmField()
{
}

std::string FarmField::toString() const
{
    return std::to_string(id + 1) + ". " + (empty() ? (this->waterAmount > 0 ? "Wet land" : "Empty land") : plant->toString() );
}

std::string FarmField::descriptionText() const
{
    std::stringstream res;
    if(!empty())
    {
        // plant description
        const PlantState* pSt = plant->getState();
        const PlantSpecies* pSp = plant->getSpecies();
        const std::string &str = pSt->toString();
        res << str << (str.size() > 0 ? "\n" : "") << pSp->getStageDesc(pSt);
    }
    else
    {
        if(waterAmount > 0)
            res << "Ah, wet soil.\nWater makes everything sticky.";
        else
            res << "It's an empty land.\nI can grow something on it.";
    }
    return res.str();
}

std::string FarmField::descriptionTitle() const
{
    return empty()
        ? (this->waterAmount > 0 ? "Wet Land" : "Empty Land")
        : (plant->getName() + " " + plant->getSpecies()->getStageName(plant->getState()));
}

bool FarmField::empty() const {
    return this->plant == nullptr || this->plant->getState() == nullptr || this->plant->getSpecies() == nullptr;
}

void FarmField::removePlant()
{
    if(!empty())
    {
        delete plant;
        plant = nullptr;
    }
}

void FarmField::deadPlant()
{
    if(!empty())
    {
        plant->getState()->dead = true;
        plant->getState()->deathTime = GameDriverSingleton::getInstance()->getFarmClock();
    }
}

void FarmField::harvest() {
    if(!empty()) {
        plant->getSpecies()->harvest(this);
    }
}

void FarmField::update() {
    if(!empty()) {
        plant->getSpecies()->update(this);
    }
}
