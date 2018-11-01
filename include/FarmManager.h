#ifndef FARMMANAGER_H
#define FARMMANAGER_H
#include "FarmBuilder.h"
#include "Farm.h"

class FarmManager : public EventManager::Observer
{
    public:
        FarmManager();
        virtual ~FarmManager();

        void start();
        void exit();

        virtual int onEvent(const std::string &eventName, void * msg);
        void buildFarm(const FarmBuilder& builder);
        Farm* getFarm() { return myFarm; }
        void setTimePaused() { if(myFarm) myFarm->clock.setPaused(true); }
        void setTimeRun() { if(myFarm) myFarm->clock.setPaused(false); }
        bool isPaused() { return myFarm ? myFarm->clock.getPause() : true; }
        int getSecond() { return myFarm ? myFarm->clock.getSeconds() : 0; }
        int getMoney() { return myFarm ? myFarm->money : 0; }
        void setMoney(int money) { if(myFarm) myFarm->money = money; }

        // void makeYardSummary(std::vector<std::string>&) const;
    protected:

    private:
        Farm* myFarm;
};

#endif // FARMMANAGER_H
