#ifndef FARMTOOLPESTICIDE_H
#define FARMTOOLPESTICIDE_H

#include "FarmTool.h"


class FarmToolPesticide : public FarmTool
{
    public:
        FarmToolPesticide();
        virtual ~FarmToolPesticide();

        virtual std::string getName();
        virtual std::string getDesc();
        virtual bool available(FarmField* target);
        virtual int action(FarmField *target);
    protected:
        std::string name, desc;
    private:
};

#endif // FARMTOOLPESTICIDE_H
