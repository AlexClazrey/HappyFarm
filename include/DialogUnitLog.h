#ifndef DIALOGUNITLOG_H
#define DIALOGUNITLOG_H

#include "DialogUnit.h"
#include "ConsoleBlockLog.h"
#include "EventManager.h"
#include <vector>
#include <string>


class DialogUnitLog : public DialogUnit, public EventManager::Observer
{
    public:
        struct DrawMsg {
            bool show;
            std::vector<std::string> logs;
        };

        DialogUnitLog();
        virtual ~DialogUnitLog();

        virtual void onKeyPressed(InputCommand* cmd, Farm* farm);
        virtual void refresh(Farm* farm);
        virtual void submit();

        virtual int onEvent(const std::string& eventName, void* msg);
    protected:

    private:
        std::vector<std::string> history;
        DrawMsg draw;
        ConsoleBlockLog cb;
};

#endif // DIALOGUNITLOG_H
