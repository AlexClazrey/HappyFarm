#include "ConsoleListA.h"

ConsoleListA::ConsoleListA()
{
    //ctor
}

ConsoleListA::~ConsoleListA()
{
    //dtor
}

void ConsoleListA::printList() {
    // read vector/select and print to screen
    int count = this->lines->size();
    for(int i = 0; i < count; i++) {
        if(i == this->select) {
            this->ctl->attrOn(A_STANDOUT);
        }
        this->ctl
            ->moveTo(CCTL::PT(this->start.x, this->start.y + i))
            ->print((*this->lines)[i])
            ->spaceTo(this->size.x + this->start.x)
            ->attrOff(A_STANDOUT);
    }
}
