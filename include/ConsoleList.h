#ifndef CONSOLELIST_H
#define CONSOLELIST_H
#include "CursorControl.h"
#include <vector>
#include <string>

class ConsoleList
{
    public:
        ConsoleList();
        ConsoleList(CCTL* ctl, const CCTL::PT& start, const CCTL::PT& size)
            : start(start), size(size), ctl(ctl), select(0), lines(nullptr) {}
        virtual ~ConsoleList();
        virtual void printList() = 0;
        virtual void setLines(std::vector<std::string>* lines) {
            this->lines = lines;
        }
        virtual void setSelect(int select) { this->select = select; }
    protected:
        CCTL::PT start;
        CCTL::PT size;
        CCTL* ctl;
        int select;
        std::vector<std::string>* lines;
    private:
};

#endif // CONSOLELIST_H
