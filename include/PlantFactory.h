#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H
#include "PlantSpecies.h"

class PlantFactory
{
    public:
        PlantFactory();
        virtual ~PlantFactory();
        virtual const PlantSpecies* getSpices(PlantSpecies::Code code);
        virtual PlantLive* makePlant(PlantSpecies::Code code);
    protected:
    private:
        static void initProtoPlant();
        static bool inited;
        static PlantSpecies* protoPlant[PlantSpecies::Code::END];
};

#endif // PLANTFACTORY_H
