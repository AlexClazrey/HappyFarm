#ifndef FARMPACKBUILDERNEW_H
#define FARMPACKBUILDERNEW_H

#include "FarmPackBuilder.h"


class FarmPackBuilderNew : public FarmPackBuilder
{
    public:
        FarmPackBuilderNew();
        virtual ~FarmPackBuilderNew();
        virtual void buildPack(FarmPack& pack) const;
    protected:

    private:
};

#endif // FARMPACKBUILDERNEW_H
