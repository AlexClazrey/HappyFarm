#ifndef PLANTLIVE_H
#define PLANTLIVE_H
#include <string>

class PlantSpecies;
class PlantState;
class PlantLive
{
    public:
        PlantLive();
        PlantLive(const PlantSpecies* species, PlantState* state) : species(species), state(state) {}
        virtual ~PlantLive();
        std::string toString() const;
        std::string getName() const;
        const PlantSpecies* getSpecies() const { return this->species; }
        PlantState* getState() const { return this->state; }
    protected:

    private:
        const PlantSpecies* species;
        PlantState* state;
};

#endif // PLANTLIVE_H
