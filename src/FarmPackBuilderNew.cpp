#include "FarmPackBuilderNew.h"
#include "FarmPack.h"

FarmPackBuilderNew::FarmPackBuilderNew()
{
}
FarmPackBuilderNew::~FarmPackBuilderNew()
{
}

void FarmPackBuilderNew::buildPack(FarmPack& pack) const {
    pack = pack.getProtoPack();
    // debug
    pack.addItem(FarmItem::Code::POTATO_SEED, 2);
}
