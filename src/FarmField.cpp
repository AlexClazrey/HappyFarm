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
    return std::to_string(id + 1) + ". " + (plant ? plant->toString() : (this->waterAmount > 0 ? "Wet land" : "Empty land"));
}

std::string FarmField::descriptionText() const
{
    std::stringstream res;
    if(plant)
    {
        // TODO plant description
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
    return plant ? plant->getName() : (this->waterAmount > 0 ? "Wet Land" : "Empty Land");
}

bool FarmField::empty() {
    return this->plant == nullptr || this->plant->getState() == nullptr || this->plant->getSpecies() == nullptr;
}

void FarmField::removePlant()
{
    if(plant)
    {
        delete plant;
        plant = nullptr;
    }
}

void FarmField::deadPlant()
{
    if(plant)
    {
        plant->getState()->dead = true;
        plant->getState()->deathTime = GameDriverSingleton::getInstance()->getFarmClock();
    }
}

void FarmField::harvest() {
    if(plant && plant->getSpecies()) {
        plant->getSpecies()->harvest(this);
    }
}

void FarmField::update() {
    if(plant && plant->getSpecies()) {
        plant->getSpecies()->update(this);
    }
}
