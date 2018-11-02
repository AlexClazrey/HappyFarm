#ifndef CONSOLEBLOCK_H
#define CONSOLEBLOCK_H
#include <iostream>
#include "CursorControl.h"

class ConsoleBlock
{
    public:
        ConsoleBlock();
        ConsoleBlock(const CCTL::PT& startPt, const CCTL::PT& size);
        ConsoleBlock(const ConsoleBlock* parent, const CCTL::PT& startPt, const CCTL::PT& size);
        virtual ~ConsoleBlock();
        virtual void top() { cursor.top(); }
        virtual void drawAll(void* msg);
        virtual void drawContent(void* msg) = 0;
        virtual void refresh() { cursor.refresh(); }
        virtual void drawAllRefresh(void* msg) { drawAll(msg); refresh(); }
        virtual void drawAfterTop() {}
    protected:
        CCTL cursor;
        bool makeTop;
    private:
};

#endif // CONSOLEBLOCK_H
