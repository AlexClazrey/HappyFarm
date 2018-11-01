#ifndef CONSOLEBLOCKMENU_H
#define CONSOLEBLOCKMENU_H

#include "ConsoleBlock.h"


class ConsoleBlockMenu : public ConsoleBlock
{
    public:
        ConsoleBlockMenu();
        virtual ~ConsoleBlockMenu();
        virtual void drawContent(void*);
    protected:

    private:
};

#endif // CONSOLEBLOCKMENU_H
