#ifndef CONSOLELISTA_H
#define CONSOLELISTA_H

#include "ConsoleList.h"


class ConsoleListA : public ConsoleList
{
    public:
        ConsoleListA();
        ConsoleListA(CCTL* ctl, const CCTL::PT& start, const CCTL::PT& size)
            : ConsoleList(ctl, start, size) {}
        virtual ~ConsoleListA();
        virtual void printList();
    protected:

    private:
};

#endif // CONSOLELISTA_H
