#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "InputCommand.h"
#include "EventManager.h"
#include <string>
#include <ncurses.h>

class InputManager : public EventManager::Observer
{
    public:
        InputManager();
        virtual ~InputManager();
        void start();
        void exit();
        int onEvent(const std::string& eventName, void* msg);
    protected:

    private:
        static const int ReadKeyInterval;
        static const int TimeEventInterval;
        int timeEventLeft;
        bool stopFlag;
        WINDOW* win;
        InputCommand::Key checkKey(char keys[], int keyCount);
};

#endif // INPUTMANAGER_H
