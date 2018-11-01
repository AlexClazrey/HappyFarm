#ifndef PLANTSPECIES_H
#define PLANTSPECIES_H
#include "FarmItem.h"
#include "DeleteCallback.h"
#include <string>

class PlantLive;
class FarmField;
class PlantState;
class PlantSpecies
{
public:
    enum Code {
        POTATO,
        CUCUMBER,
        END
    };
    class Strategy
    {
    public:
        class Fruit : public DeleteCallback
        {
        public:
            // return fruit count
            virtual int execute(PlantState*) const = 0;
            virtual bool canHarvest(PlantState*) const = 0;
            virtual FarmItem::Code getFruitCode(PlantState*) const = 0;
        };
        class HarvestLive : public DeleteCallback
        {
        public:
            // return 0-x for stage change to, -1 for dead, -2 for vanish
            int virtual execute(PlantState*) const = 0;
        };
        class HarvestSeed : public DeleteCallback
        {
        public:
            // return seed count from harvest
            virtual int execute(PlantState*) const = 0;
            virtual FarmItem::Code getSeedCode() const = 0;
        };
        class Worm : public DeleteCallback
        {
        public:
            // return if get worm
            bool virtual execute(PlantState*) const = 0;
        };
        class Water : public DeleteCallback
        {
        public:
            // return if dry up
            bool virtual execute(FarmField*) const = 0;
            bool virtual isDry(FarmField*) const = 0;
        };
        class Grow : public DeleteCallback
        {
        public:
            // return stage number
            virtual int execute(PlantState*) const = 0;
            virtual bool canGrow(PlantState*) const = 0;
            virtual std::string getStageName(PlantState*) const = 0;
            virtual std::string getStageDesc(PlantState*) const = 0;
        };
    };

    PlantSpecies();
    PlantSpecies(std::string name,
                 Strategy::Fruit* stf,
                 Strategy::HarvestLive* sthl,
                 Strategy::HarvestSeed* sths,
                 Strategy::Worm* stwo,
                 Strategy::Water* stwa,
                 Strategy::Grow* stg)
                 : name(name), StF(stf), StHL(sthl), StHS(sths), StWorm(stwo), StWater(stwa), StGrow(stg) {}
    virtual ~PlantSpecies();
    virtual std::string toString() const { return this->name; }
    virtual std::string getName() const { return this->name; }
    virtual std::string getStageName(PlantState *ps) const { return this->StGrow->getStageName(ps); }
    virtual std::string getStageDesc(PlantState *ps) const { return this->StGrow->getStageDesc(ps); }
    virtual void harvest(FarmField*) const;
    virtual void update(FarmField*) const;

protected:
    std::string name;
    Strategy::Fruit* StF;
    Strategy::HarvestLive* StHL;
    Strategy::HarvestSeed* StHS;
    Strategy::Worm* StWorm;
    Strategy::Water* StWater;
    Strategy::Grow* StGrow;
private:
};

typedef PlantSpecies::Strategy PSS;

#endif // PLANTSPECIES_H
