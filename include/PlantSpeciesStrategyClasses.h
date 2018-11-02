#ifndef PLANTSPECIESSTRATEGYCLASSES_H
#define PLANTSPECIESSTRATEGYCLASSES_H
#include "PlantSpecies.h"
#include "FarmItem.h"
#include <vector>
#include <random>
#include <functional>

class PlantSpeciesStrategyClasses
{
    public:
        class WaterA : public PSS::Water {
        public:
            WaterA(int amountPerSecond) : amount(amountPerSecond) {}
            virtual ~WaterA() {}
            bool execute(FarmField*) const;
            bool isDry(FarmField*) const;
            void destruction() { delete this; }
        private:
            int amount;
        };
        class GrowA : public PSS::Grow {
        public:
            struct Stage {
                int grows;
                std::string name;
                std::string desc;
                Stage(int grows, const std::string& name, const std::string& desc)
                    : grows(grows), name(name), desc(desc) {}
            };
            GrowA(const std::vector<Stage>& stages) : stages(stages) {}
            virtual ~GrowA() {}
            int execute(PlantState*) const;
            bool canGrow(PlantState*) const;
            std::string getStageName(const PlantState*) const;
            std::string getStageDesc(const PlantState*) const;
            void destruction() { delete this; }
        private:
            std::vector<Stage> stages;
        };
        class FruitA : public PSS::Fruit {
        public:
            FruitA(FarmItem::Code fruitCode, int fruitStage, int normal, int abnormal, int rate)
                : fruitCode(fruitCode), fruitStage(fruitStage), normal(normal), abnormal(abnormal), abnormalRate(rate) {}
            virtual ~FruitA() {}
            int execute(PlantState*) const;
            FarmItem::Code getFruitCode(PlantState*) const { return fruitCode; }
            bool canHarvest(PlantState*) const;
            void destruction() { delete this; }
        private:
            FarmItem::Code fruitCode;
            int fruitStage;
            int normal;
            int abnormal;
            int abnormalRate;
        };
        class FruitSSR : public PSS::Fruit {
        public:
            FruitSSR(FarmItem::Code fruitCode, FarmItem::Code SSRCode, int rate) {}
            virtual ~FruitSSR() {}
            void destruction() { delete this; }
        private:
            // TODO SSR
        };
        class HarvestLiveA : public PSS::HarvestLive {
        public:
            HarvestLiveA(int liveCycle, int toStage, bool vanish) : liveCycle(liveCycle), stage(toStage), vanish(vanish) {}
            virtual ~HarvestLiveA() {}
            int execute(PlantState*) const;
            void destruction() { delete this; }
        private:
            int liveCycle;
            int stage;
            bool vanish;
        };
        class HarvestSeedA : public PSS::HarvestSeed {
        public:
            HarvestSeedA(FarmItem::Code seedCode, int normal, int abnormal, int rate)
                : seedCode(seedCode), normal(normal), abnormal(abnormal), abnormalRate(rate) {}
            virtual ~HarvestSeedA() {}
            int execute(PlantState*) const;
            FarmItem::Code getSeedCode() const { return seedCode; }
            void destruction() { delete this; }
        private:
            FarmItem::Code seedCode;
            int normal;
            int abnormal;
            int abnormalRate;
        };
        class WormA : public PSS::Worm {
        public:
            WormA(int rate) : wormRate(rate) {}
            virtual ~WormA() {}
            bool execute(PlantState*) const;
            void destruction() { delete this; }
        private:
            int wormRate;
        };

        PlantSpeciesStrategyClasses();
        virtual ~PlantSpeciesStrategyClasses();

        static int playDice(int normal, int abnormal, int abnormalRate);
    protected:
    private:
        static std::default_random_engine generator;
        static std::uniform_int_distribution<int> distribution;
        static std::function<int()> percentDice;
};
typedef PlantSpeciesStrategyClasses PSSC;

#endif // PLANTSPECIESSTRATEGYCLASSES_H
