#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "ConsoleBlock.h"
#include "EventManager.h"
#include "DrawCommand.h"
#include <vector>

class DisplayManager : public EventManager::Observer
{
    public:
        DisplayManager();
        virtual ~DisplayManager();
        virtual int onEvent(const std::string &eventName, void* msg);
        void start();
        void exit();
    protected:

    private:
        std::vector<DrawCommand*> drawList;

        static bool compareCommand(DrawCommand*, DrawCommand*);
};

#endif // DISPLAYMANAGER_H
