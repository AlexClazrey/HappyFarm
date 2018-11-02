#include "ConsoleBlockField.h"
#include "DialogUnitField.h"
#include "CursorControl.h"

ConsoleBlockField::ConsoleBlockField()
    : ConsoleBlock(CCTL::PT(0,0), CCTL::PT(70, 20))
{
    this->cursor.borderOn();
    this->cla = new ConsoleListA(&cursor, CCTL::PT(8, 4), CCTL::PT(47, 10));
}

ConsoleBlockField::~ConsoleBlockField()
{
    if(cla)
        delete cla;
}

void ConsoleBlockField::drawContent(void* rawMsg) {
    DialogUnitField::DrawMsg* msg = (DialogUnitField::DrawMsg*) rawMsg;
    if(msg->show) {
        this->cursor.show()
            ->attrOn(A_BOLD)
            ->moveTo(CCTL::PT(6, 2))
            ->print("Your Yard")
            ->attrOff(A_BOLD)
            ->refresh();
        this->cla->setLines(&msg->fields);
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

