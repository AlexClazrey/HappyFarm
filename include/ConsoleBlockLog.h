#ifndef CONSOLEBLOCKLOG_H
#define CONSOLEBLOCKLOG_H

#include "ConsoleBlock.h"


class ConsoleBlockLog : public ConsoleBlock
{
    public:
        ConsoleBlockLog();
        virtual ~ConsoleBlockLog();
        virtual void drawContent(void* msg);
    protected:

    private:
};

#endif // CONSOLEBLOCKLOG_H
