#include "PlantSpeciesStrategyClasses.h"
#include "FarmField.h"
#include "PlantLive.h"
#include "PlantState.h"
#include "GameDriverSingleton.h"
#include <ctime>

std::default_random_engine PSSC::generator(static_cast<long unsigned int>(std::time(0)));
std::uniform_int_distribution<int> PSSC::distribution(0, 99);
std::function<int()> PSSC::percentDice = std::bind(PSSC::distribution, PSSC::generator);

PlantSpeciesStrategyClasses::PlantSpeciesStrategyClasses()
{
    //ctor
}

PlantSpeciesStrategyClasses::~PlantSpeciesStrategyClasses()
{
    //dtor
}

// caller of this method should update dry boolean in PlantState
bool PlantSpeciesStrategyClasses::WaterA::execute(FarmField* field) const {
    int water = field->getWater();
    if(water <= this->amount) {
        field->getPlant()->getState()->dry = true;
        field->setWater(0);
        return true;
    } else {
        field->getPlant()->getState()->dry = false;
        field->setWater(water - this->amount);
        return false;
    }
}

bool PlantSpeciesStrategyClasses::WaterA::isDry(FarmField* field) const {
    return field->getWater() <= 0;
}

// caller of this method should update stage in PlantState
int PlantSpeciesStrategyClasses::GrowA::execute(PlantState* ps) const {
    if(this->canGrow(ps)) {
        ps->grow++;
    }
    if(ps->stage >= 0 && ps->stage < (int)stages.size()) {
        if(stages[ps->stage].grows == -1) {
            return ps->stage;
        } else if(ps->grow >= stages[ps->stage].grows && ps->stage < (int)(stages.size() - 1)) {
            ps->grow = 0;
            return ps->stage + 1;
        }
    } else {
        GameDriverSingleton::getInstance()->addLog("[ERROR] Plant stage invalid.");
    }
    return ps->stage;
}

bool PlantSpeciesStrategyClasses::GrowA::canGrow(PlantState *ps) const {
    return !(ps->dry || ps->dead || ps->worm || ps->mature);
}

std::string PlantSpeciesStrategyClasses::GrowA::getStageName(PlantState* ps) const {
    if(ps->stage >= 0 && ps->stage < (int)this->stages.size()) {
        return stages[ps->stage].name;
    }
    return "Mutated";
}

std::string PlantSpeciesStrategyClasses::GrowA::getStageDesc(PlantState* ps) const {
    if(ps->stage >= 0 && ps->stage < (int)this->stages.size()) {
        return stages[ps->stage].desc;
    }
    return "Mutated plant, I have no idea what it will develop into.";
}

int PlantSpeciesStrategyClasses::FruitA::execute(PlantState *ps) const {
    if(ps->stage == fruitStage && ps->fruit <= 0) {
        return ps->fruit = playDice(normal, abnormal, abnormalRate);
    }
    return ps->fruit;
}

bool PlantSpeciesStrategyClasses::FruitA::canHarvest(PlantState*ps) const {
    return ps->fruit > 0;
}

int PlantSpeciesStrategyClasses::HarvestLiveA::execute(PlantState *ps) const {
    if(ps->harvestCount >= this->liveCycle - 1) {
        return vanish ? -2 : -1;
    }
    return stage;
}

int PlantSpeciesStrategyClasses::HarvestSeedA::execute(PlantState *ps) const {
    return playDice(normal, abnormal, abnormalRate);
}

bool PlantSpeciesStrategyClasses::WormA::execute(PlantState *ps) const {
    return playDice(0, 1, wormRate) == 1;
}

int PlantSpeciesStrategyClasses::playDice(int normal, int abnormal, int rate) {
    return percentDice() < rate ? abnormal : normal;
}


