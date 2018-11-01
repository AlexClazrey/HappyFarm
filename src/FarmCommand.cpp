#include "FarmCommand.h"
#include "FarmField.h"
#include "PlantFactory.h"
#include "PlantSpecies.h"
#include "FarmItem.h"
#include "FarmPack.h"

FarmCommand::FarmCommand()
{
    //ctor
}

FarmCommand::~FarmCommand()
{
    //dtor
}

int FarmCommandPlant::toField() {
    ff->addPlant(PlantFactory().makePlant(plantCode));
    return 0;
}

int FarmCommandPlant::toPack(FarmPack* pack) {
    pack->removeItem(seedCode);
    return 0;
}

int FarmCommandHarvest::toField() {
    ff->harvest();
    return 0;
}

int FarmCommandHarvest::toPack(FarmPack *pack) {
    return 0;
}
