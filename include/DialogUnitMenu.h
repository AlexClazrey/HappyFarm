#ifndef DIALOGUNITMENU_H
#define DIALOGUNITMENU_H

#include "DialogUnit.h"
#include "ConsoleBlockMenu.h"
#include "EventManager.h"
#include <vector>
#include <string>

class DialogUnitMenu : public DialogUnit, public EventManager::Observer
{
    public:
        static const std::string FOCUS_NAME;
        struct DrawMsg {
            bool show;
            int select;
            std::vector<std::string> options;
        };
        DialogUnitMenu();
        virtual ~DialogUnitMenu();

        virtual void onKeyPressed(InputCommand* cmd, Farm* farm);
        virtual void refresh(Farm* farm);
        virtual void submit();

        virtual int onEvent(const std::string& ev, void* msg);
    protected:

    private:
        ConsoleBlockMenu cb;
        DrawMsg msg;

        void triggerNewGame();
        void triggerLoadGame();
        void triggerExitGame();
};

#endif // DIALOGUNITMENU_H
