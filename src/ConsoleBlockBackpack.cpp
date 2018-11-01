#include "ConsoleBlockBackpack.h"
#include "ConsoleListA.h"
#include "DialogUnitBackpack.h"

ConsoleBlockBackpack::ConsoleBlockBackpack()
    : ConsoleBlock(CCTL::PT(0,0), CCTL::PT(70, 20))
{
    this->cursor.borderOn();
    this->cla = new ConsoleListA(&this->cursor, CCTL::PT(8, 4), CCTL::PT(47, 10));
}

ConsoleBlockBackpack::~ConsoleBlockBackpack()
{
    if(cla)
        delete cla;
}

void ConsoleBlockBackpack::drawContent(void* rawMsg) {
    DialogUnitBackpack::DrawMsg* msg = (DialogUnitBackpack::DrawMsg*) rawMsg;
    if(msg->show) {
        this->cursor.show()
            ->attrOn(A_BOLD)
            ->moveTo(CCTL::PT(30, 2))
            ->print("BackPack")
            ->attrOff(A_BOLD);
        this->cla->setLines(&msg->goods);
        this->cla->setSelect(msg->select);
        this->cla->printList();
        // draw time and money
        this->cursor.moveTo(CCTL::PT(8, 15))
            ->print("Time: ")
            ->print(msg->time)
            ->spaceTo(20 < this->cursor.getX() ? 30 : 20)
            ->print("Money: ")
            ->print(msg->money);
    } else {
        this->cursor.clear()->hide();
    }
}
