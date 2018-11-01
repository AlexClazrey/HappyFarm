#ifndef DIALOGUNITTIME_H
#define DIALOGUNITTIME_H
#include "EventManager.h"
#include "DialogUnit.h"
#include <ctime>

class DialogUnitTime : public DialogUnit, public EventManager::Observer
{
    public:
        DialogUnitTime();
        virtual ~DialogUnitTime();
        virtual void onKeyPressed(InputCommand* cmd, Farm* farm);
        virtual void refresh(Farm* farm);
        virtual void submit();

        virtual int onEvent(const std::string& eventName, void* msg);
    protected:

    private:
        bool kickoff;
        std::time_t time;
};

#endif // DIALOGUNITTIME_H
