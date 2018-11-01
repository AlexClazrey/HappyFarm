#ifndef CONSOLEBLOCKBACKPACK_H
#define CONSOLEBLOCKBACKPACK_H

#include "ConsoleBlock.h"
#include "ConsoleList.h"

class ConsoleBlockBackpack : public ConsoleBlock
{
    public:
        ConsoleBlockBackpack();
        virtual ~ConsoleBlockBackpack();

        void drawContent(void* rawMsg);
    protected:

    private:
        ConsoleList* cla;
};

#endif // CONSOLEBLOCKBACKPACK_H
