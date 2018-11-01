#ifndef FARMTOOLPLANT_H
#define FARMTOOLPLANT_H

#include "FarmTool.h"
#include "PlantSpecies.h"

class FarmToolPlant : public FarmTool
{
    public:
        FarmToolPlant();
        virtual ~FarmToolPlant();
        virtual std::string getName();
        virtual std::string getDesc();
        virtual bool available(FarmField* target);
        virtual int action(FarmField *target);

    protected:

    private:
        int plant(FarmField *, PlantSpecies::Code plantCode, FarmItem::Code seedCode, const std::string& plantName);
};

#endif // FARMTOOLPLANT_H
