#ifndef DIALOGUNITFIELD_H
#define DIALOGUNITFIELD_H
#include "ConsoleBlockField.h"
#include "DialogUnit.h"
#include "EventManager.h"
#include <vector>
#include <string>

class FarmField;
class DialogUnitField : public DialogUnit, public EventManager::Observer
{
    public:
        static const std::string FOCUS_NAME;
        struct DrawMsg {
            bool show;
            bool selectOnField;
            int select;
            int time;
            int money;
            std::vector<std::string> fields;
        };
        DialogUnitField();
        virtual ~DialogUnitField();

        virtual void onKeyPressed(InputCommand* cmd, Farm* farm);
        virtual void refresh(Farm* farm);
        virtual void submit();

        virtual int onEvent(const std::string& ev, void* msg);
    protected:

    private:
        DrawMsg msg;
        ConsoleBlockField cb;

        void makeSummary(Farm* farm);
        void makeDesc(Farm* farm);
        void openFieldMenu(FarmField *field, Farm* farm);

        int fieldSize() { return (int)this->msg.fields.size(); }
};

#endif // DIALOGUNITFIELD_H
