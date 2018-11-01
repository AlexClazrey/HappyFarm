#ifndef FARMBUILDERLOAD_H
#define FARMBUILDERLOAD_H

#include "FarmBuilder.h"


class FarmBuilderLoad : public FarmBuilder
{
    public:
        FarmBuilderLoad();
        virtual ~FarmBuilderLoad();
        virtual Farm* buildFarm() const;

    protected:

    private:
};

#endif // FARMBUILDERLOAD_H
