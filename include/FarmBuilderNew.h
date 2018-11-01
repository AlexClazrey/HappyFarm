#ifndef FARMBUILDERNEW_H
#define FARMBUILDERNEW_H

#include "FarmBuilder.h"


class FarmBuilderNew : public FarmBuilder
{
    public:
        static const int INIT_MONEY;
        FarmBuilderNew();
        virtual ~FarmBuilderNew();
        Farm* buildFarm() const;
    protected:

    private:
};

#endif // FARMBUILDERNEW_H
