#include "PlantLive.h"
#include "PlantSpecies.h"
#include "PlantState.h"

PlantLive::PlantLive()
{
    //ctor
}

PlantLive::~PlantLive()
{
    if(this->state)
        delete this->state;
}

std::string PlantLive::toString() const
{
    if(this->species)
    {
        return species->toString() + (state ? "\t" + species->getStageName(state) + " " + state->toString() : "");
    }
    else
    {
        return std::string("Empty");
    }
}


std::string PlantLive::getName() const
{
    return species ? species->getName() : "";
}
