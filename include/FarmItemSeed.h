#ifndef FARMITEMSEED_H
#define FARMITEMSEED_H

#include "FarmItem.h"
#include "PlantSpecies.h"

class PlantSpecies;
class FarmItemSeed : public FarmItem
{
    public:
        FarmItemSeed();
        FarmItemSeed(FarmItem::Code code, const std::string& name, const std::string& desc, int buy, int sold, PlantSpecies::Code speciesCode);
        virtual ~FarmItemSeed();
        virtual PlantSpecies::Code getSpecies() const { return this->species; }
    protected:
    private:
        PlantSpecies::Code species;
};

#endif // FARMITEMSEED_H
