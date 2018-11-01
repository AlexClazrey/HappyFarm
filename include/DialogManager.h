#ifndef DIALOGMANAGER_H
#define DIALOGMANAGER_H
#include "Farm.h"
#include "EventManager.h"
#include "DialogUnit.h"
#include <vector>


class DialogManager : public EventManager::Observer
{
    public:
        struct ChangeFocusMsg {
            std::string name;
            Farm* farm;
            void* msg;
            ChangeFocusMsg();
            ChangeFocusMsg(const std::string &name, Farm* farm, void* msg)
                : name(name), farm(farm), msg(msg) {}
        };

        DialogManager();
        virtual ~DialogManager();
        virtual int onEvent(const std::string &eventName, void* obj);
        void start();
        void exit();

    protected:
        void refresh(Farm* model);
        void setFocus(DialogUnit* focus) { this->focused = focus; }

    private:
        DialogUnit* focused;
        std::vector<DialogUnit*> units;
};

#endif // DIALOGMANAGER_H
