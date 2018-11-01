#ifndef FARMTOOLHARVEST_H
#define FARMTOOLHARVEST_H

#include "FarmTool.h"


class FarmToolHarvest : public FarmTool
{
    public:
        FarmToolHarvest();
        virtual ~FarmToolHarvest();

        virtual std::string getName() { return name; }
        virtual std::string getDesc() { return desc; }
        virtual bool available(FarmField* target);
        virtual int action(FarmField*);
    protected:

    private:
        std::string name, desc;
};

#endif // FARMTOOLHARVEST_H
