#include "PlantSpecies.h"
#include "PlantLive.h"
#include "PlantState.h"
#include "FarmField.h"
#include "GameDriverSingleton.h"

PlantSpecies::PlantSpecies()
{
}

PlantSpecies::~PlantSpecies()
{
    // delete abstract class will cause potential problem, so use virtual function here
    if(StF) StF->destruction();
    if(StHL) StHL->destruction();
    if(StHS) StHS->destruction();
    if(StGrow) StGrow->destruction();
    if(StWorm) StWorm->destruction();
    if(StWater) StWater->destruction();
}

void PlantSpecies::harvest(FarmField *ff) const {
    PlantState* ps = ff->getPlant()->getState();
    if(StF->canHarvest(ps)) {
        ps->mature = false;
        int fruitCount = StF->execute(ps);
        FarmItem::Code fruitCode = StF->getFruitCode(ps);
        int live = StHL->execute(ps);
        int seedCount = StHS->execute(ps);
        FarmItem::Code seedCode = StHS->getSeedCode();
        if(fruitCount > 0) {
            GameDriverSingleton::getInstance()->addItem(fruitCode, fruitCount);
        }
        if(seedCount > 0) {
            GameDriverSingleton::getInstance()->addItem(seedCode, seedCount);
        }
        if(live >= 0) {
            ps->fruit = 0;
            ps->stage = live;
            ps->grow = 0;
            ps->mature = false;
            ps->harvestCount++;
        } else if(live == -1) {
            ff->deadPlant();
        } else if(live == -2) {
            ff->removePlant();
        }
    }
}

void PlantSpecies::update(FarmField* ff) const {
    PlantState* ps = ff->getPlant()->getState();
    bool dry = StWater->isDry(ff);
    ps->dry = dry;
    int stage = StGrow->execute(ps);
    ps->stage = stage;
    int fruit = StF->execute(ps);
    if(fruit > 0) {
        ps->mature = true;
    } else if(StGrow->canGrow(ps)) {
        bool worm = StWorm->execute(ps);
        ps->worm = worm;
        if(worm) ps->wormTime = GameDriverSingleton::getInstance()->getFarmClock();
        dry = StWater->execute(ff);
        ps->dry = dry;
        if(dry) ps->dryTime = GameDriverSingleton::getInstance()->getFarmClock();
    }
}
