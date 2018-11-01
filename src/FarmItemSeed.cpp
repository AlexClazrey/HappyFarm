#include "FarmItemSeed.h"
#include "PlantSpecies.h"
#include "PlantFactory.h"

FarmItemSeed::FarmItemSeed()
{
    //ctor
}
FarmItemSeed::FarmItemSeed(FarmItem::Code code,
                           const std::string& name,
                           const std::string& desc,
                           int buy,
                           int sold,
                           PlantSpecies::Code speciesCode)
    : FarmItem(FarmItem::Type::SEED, code, name, desc, buy, sold), species(speciesCode)
{
}

FarmItemSeed::~FarmItemSeed()
{
    //dtor
}
