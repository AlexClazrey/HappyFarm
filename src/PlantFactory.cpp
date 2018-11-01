#include "PlantFactory.h"
#include "PlantState.h"
#include "PlantLive.h"
#include "PlantSpeciesStrategyClasses.h"
#include "GameDriverSingleton.h"
#include <vector>

PlantSpecies* PlantFactory::protoPlant[PlantSpecies::Code::END];
bool PlantFactory::inited = false;

PlantFactory::PlantFactory()
{
    this->initProtoPlant();
}

PlantFactory::~PlantFactory()
{
    //dtor
}

const PlantSpecies* PlantFactory::getSpices(PlantSpecies::Code code) {
    if(code >= 0 && code < PlantSpecies::Code::END)
        return protoPlant[code];
    else
        return nullptr;
}

PlantLive* PlantFactory::makePlant(PlantSpecies::Code code) {
    PlantState *ps = new PlantState();
    ps->plantTime = GameDriverSingleton::getInstance()->getFarmClock();
    return new PlantLive(getSpices(code), ps);
}

void PlantFactory::initProtoPlant() {
    if(!inited) {
        std::vector<PSSC::GrowA::Stage> stages;
        stages.push_back(PSSC::GrowA::Stage(4, "Seed", "Being buried by earth."));
        stages.push_back(PSSC::GrowA::Stage(4, "Sprout", "Those green leaves give me hope."));
        stages.push_back(PSSC::GrowA::Stage(4, "Flower", "Clusters of white flowers are beautiful."));
        stages.push_back(PSSC::GrowA::Stage(-1, "Fruit", "Flowers have withered, maybe I can dig now."));
        protoPlant[PlantSpecies::Code::POTATO]
            = new PlantSpecies("Potato",
                                new PSSC::FruitA(FarmItem::Code::POTATO_FRUIT, 3, 1, 2, 50),
                                new PSSC::HarvestLiveA(1, 1, true),
                                new PSSC::HarvestSeedA(FarmItem::Code::POTATO_SEED, 0, 1, 20),
                                new PSSC::WormA(3),
                                new PSSC::WaterA(3),
                                new PSSC::GrowA(stages)
                                );
    }
}
