#ifndef PLANTSTATE_H
#define PLANTSTATE_H
#include <string>

class PlantState
{
    public:
        PlantState();
        virtual ~PlantState();

        int stage;
        int grow;
        int fruit;

        bool worm;
        bool dry;
        bool dead;
        bool mature; // this is only used for in-line quick access

        int plantTime;
        int wormTime;
        int dryTime;
        int deathTime;

        int harvestCount;

        virtual std::string toString() const;
    protected:

    private:
};

#endif // PLANTSTATE_H
