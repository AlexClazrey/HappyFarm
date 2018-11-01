#ifndef CONSOLEBLOCKDESC_H
#define CONSOLEBLOCKDESC_H

#include "ConsoleBlock.h"
#include "ConsoleList.h"

class ConsoleBlockDesc : public ConsoleBlock
{
    public:
        ConsoleBlockDesc();
        virtual ~ConsoleBlockDesc();

        virtual void drawContent(void* msg);
    protected:

    private:
        ConsoleList* cla;
};

#endif // CONSOLEBLOCKDESC_H
