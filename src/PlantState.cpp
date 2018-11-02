#include "PlantState.h"
#include <string>

PlantState::PlantState()
{
    stage = fruit = grow = 0;
    dry = dead = worm = mature = false;
    deathTime = dryTime = wormTime = plantTime = 0;
    harvestCount = 0;
}

PlantState::~PlantState()
{
    //dtor
}

std::string PlantState::toString() const {
    if(dead) {
        return std::string("[Dead]");
    }
    if(mature) {
        return std::string("[Can Harvest]");
    }
    return std::string(dry ? "[Dry] " : "") + (worm ? "[Worm] " : "");
}
