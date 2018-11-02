#include "ConsoleBlockShop.h"
#include "ConsoleListA.h"
#include "DialogUnitShop.h"

ConsoleBlockShop::ConsoleBlockShop()
    : ConsoleBlock(CCTL::PT(0,0), CCTL::PT(70, 20))
{
    this->cursor.borderOn();
    this->cla = new ConsoleListA(&cursor, CCTL::PT(8, 4), CCTL::PT(47, 10));
}

ConsoleBlockShop::~ConsoleBlockShop()
{
    if(cla)
        delete cla;
}

void ConsoleBlockShop::drawContent(void* rawMsg) {
    DialogUnitShop::DrawMsg* msg = (DialogUnitShop::DrawMsg*) rawMsg;
    if(msg->show) {
        this->cursor.show()
            ->attrOn(A_BOLD)
            ->moveTo(CCTL::PT(50, 2))
            ->print("The Shop")
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
