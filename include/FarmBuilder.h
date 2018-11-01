#ifndef FARMBUILDER_H
#define FARMBUILDER_H
#include "Farm.h"

class FarmBuilder
{
    public:
        FarmBuilder();
        virtual ~FarmBuilder();
        virtual Farm* buildFarm() const = 0;
    protected:

    private:
};

#endif // FARMBUILDER_H
