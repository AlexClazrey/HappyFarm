#include "ConsoleBlockLog.h"
#include "DialogUnitLog.h"

ConsoleBlockLog::ConsoleBlockLog() : ConsoleBlock(CCTL::PT(0, 20), CCTL::PT(70, 10))
{
    this->cursor.borderOn();
}

ConsoleBlockLog::~ConsoleBlockLog()
{
}

void ConsoleBlockLog::drawContent(void* rawMsg) {
    DialogUnitLog::DrawMsg* msg = (DialogUnitLog::DrawMsg*) rawMsg;
    if(msg->show) {
        this->cursor.show();
        int logCount = msg->logs.size();
        for(int id = 0; id < logCount; id++) {
            this->cursor.moveTo(CCTL::PT(2, id))
                ->print(msg->logs[id]);
        }
    } else {
        this->cursor.clear()->hide();
    }
}
