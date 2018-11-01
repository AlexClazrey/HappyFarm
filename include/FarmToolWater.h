#ifndef FARMTOOLWATER_H
#define FARMTOOLWATER_H
#include "FarmTool.h"
#include <string>

class FarmToolWater : public FarmTool
{
    public:
        FarmToolWater();
        virtual ~FarmToolWater();

        virtual std::string getName();
        virtual std::string getDesc();
        virtual bool available(FarmField* target);
        virtual int action(FarmField *target);
    protected:
        std::string name, desc;
        int waterAmount;
    private:
};

#endif // FARMTOOLWATER_H
