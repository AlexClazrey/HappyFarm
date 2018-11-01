#ifndef CONSOLEBLOCKSHOP_H
#define CONSOLEBLOCKSHOP_H

#include "ConsoleBlock.h"
#include "ConsoleList.h"


class ConsoleBlockShop : public ConsoleBlock
{
    public:
        ConsoleBlockShop();
        virtual ~ConsoleBlockShop();
        virtual void drawContent(void* msg);
    protected:

    private:
        ConsoleList* cla;
};

#endif // CONSOLEBLOCKSHOP_H
