#ifndef FARM_H
#define FARM_H
#include "EventManager.h"
#include "FarmPack.h"
#include "FarmYard.h"
#include "FarmClock.h"
#include "FarmToolbox.h"

class FarmCommand;
class Farm
{
    public:
        Farm();
        virtual ~Farm();
        FarmPack pack;
        FarmYard yard;
        FarmClock clock;
        FarmToolbox toolbox;
        int money;

        int executeCommand(FarmCommand* cmd);
    protected:

    private:

};

#endif // FARM_H
