#ifndef CONSOLELIST_H
#define CONSOLELIST_H
#include "CursorControl.h"
#include "ConsoleBlock.h"
#include <vector>
#include <string>

class ConsoleList
{
    public:
        ConsoleList();
        ConsoleList(CCTL* ctl, const CCTL::PT& start, const CCTL::PT& size)
            : select(0), start(start), size(size), ctl(ctl), lines (nullptr) {}
        virtual ~ConsoleList();
        virtual void setLines(std::vector<std::string>* lines) {
            this->lines = lines;
        }
        virtual void setSelect(int select) { this->select = select; }
        virtual void printList() = 0;
    protected:
        int select;
        CCTL::PT start, size;
        CCTL* ctl;
        std::vector<std::string>* lines;
    private:
};

#endif // CONSOLELIST_H
