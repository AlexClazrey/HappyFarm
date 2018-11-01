#ifndef CONSOLEBLOCKFIELD_H
#define CONSOLEBLOCKFIELD_H
#include "ConsoleBlock.h"
#include "ConsoleListA.h"

class ConsoleBlockField : public ConsoleBlock
{
    public:
        ConsoleBlockField();
        virtual ~ConsoleBlockField();

        virtual void drawContent(void*);
    protected:
    private:
        ConsoleList* cla;
};

#endif // CONSOLEBLOCKFIELD_H
