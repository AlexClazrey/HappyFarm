#include "FarmBuilderNew.h"
#include "FarmPackBuilderNew.h"

const int FarmBuilderNew::INIT_MONEY = 200;

FarmBuilderNew::FarmBuilderNew()
{
}

FarmBuilderNew::~FarmBuilderNew()
{
}

Farm* FarmBuilderNew::buildFarm() const {
    Farm* target = new Farm();
    FarmPackBuilderNew().buildPack(target->pack);
    target->money = FarmBuilderNew::INIT_MONEY;
    return target;
}
