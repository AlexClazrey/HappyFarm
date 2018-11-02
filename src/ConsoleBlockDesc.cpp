#include "ConsoleBlockDesc.h"
#include "DialogUnitDesc.h"
#include "ConsoleListA.h"
#include "MenuOption.h"

ConsoleBlockDesc::ConsoleBlockDesc() : ConsoleBlock(CCTL::PT(70,0), CCTL::PT(40, 30))
{
    this->cursor.borderOn();
    this->cla = new ConsoleListA(&cursor, CCTL::PT(3, 4), CCTL::PT(25, 10));
}

ConsoleBlockDesc::~ConsoleBlockDesc()
{
}

void ConsoleBlockDesc::drawContent(void* rawMsg) {
    DialogUnitDesc::DrawMsg* msg = (DialogUnitDesc::DrawMsg*)rawMsg;
    if(msg->show) {
        CCTL::PT leftCorner(3, 2);
        this->cursor.show();
        if(msg->mode == 1) {
            // description mode
            DialogUnitDesc::DescMsg& dmsg = *msg->desc;
            this->cursor.moveTo(leftCorner)
                ->attrOn(A_BOLD)
                ->print(dmsg.title)
                ->attrOff(A_BOLD);
            int lineCount = dmsg.lines.size();
            for(int id = 0; id < lineCount; id++) {
                this->cursor.moveTo(CCTL::PT(3, id + 4))
                    ->print(dmsg.lines[id]);
            }
        } else if(msg->mode == 2) {
            // options mode
            DialogUnitDesc::OptionsMsg& opts = *msg->opts;
            this->cursor.moveTo(leftCorner)
                ->attrOn(A_BOLD)
                ->print(opts.title)
                ->attrOff(A_BOLD);
            std::vector<std::string> names;
            for(auto &option : opts.options) {
                names.push_back(option.getName());
            }
            if(opts.addCancel) {
                names.push_back("Cancel");
            }
            this->cla->setSelect(opts.select);
            if(names.size() == 0) {
                names.push_back(opts.emptyMsg.size() > 0 ? opts.emptyMsg : "<No Actions>");
                this->cla->setSelect(-1);
            }
            this->cla->setLines(&names);
            this->cla->printList();
            this->cursor.moveTo(CCTL::PT(3, 21))
                ->print(opts.select >= 0 && opts.select < (int)opts.options.size() ? opts.options[opts.select].getDesc() : "Close this menu.");
        }
    } else {
        this->cursor.clear()->hide();
    }
}
