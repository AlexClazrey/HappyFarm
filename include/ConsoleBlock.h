#ifndef CONSOLEBLOCK_H
#define CONSOLEBLOCK_H
#include <iostream>
#include "CursorControl.h"

class ConsoleBlock
{
    public:
        ConsoleBlock();
        ConsoleBlock(const CCTL::PT& startPt, const CCTL::PT& size);
        virtual ~ConsoleBlock();
        virtual void drawAll(void* msg);
        virtual void drawContent(void* msg) = 0;
    protected:
        CCTL cursor;
    private:
};

#endif // CONSOLEBLOCK_H
