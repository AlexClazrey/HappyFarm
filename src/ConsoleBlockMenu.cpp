#include "ConsoleBlockMenu.h"
#include "DialogUnitMenu.h"

// CCTL::PT(0,0), CCTL::PT(60,20)
ConsoleBlockMenu::ConsoleBlockMenu() : ConsoleBlock(CCTL::PT(0,0), CCTL::PT(110, 30))
{
    this->cursor.borderOn();
}

ConsoleBlockMenu::~ConsoleBlockMenu()
{
}

void ConsoleBlockMenu::drawContent(void* msg) {
    DialogUnitMenu::DrawMsg* content = (DialogUnitMenu::DrawMsg*)msg;
    if(content->show) {
        this->cursor.show();
        int optionCount = content->options.size();
        for(int id = 0; id < optionCount; id++) {
            if(content->select == id) {
                this->cursor.attrOn(A_STANDOUT);
            }
            this->cursor.moveTo(CCTL::PT(10, id + 2))
                ->print(id + 1)
                ->print(". ")
                ->print(content->options[id])
                ->spaceTo(40)
                ->attrOff(A_STANDOUT);
        }
    } else {
        this->cursor.clear()->hide();
    }
}
