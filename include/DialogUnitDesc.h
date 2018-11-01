#ifndef DIALOGUNITDESC_H
#define DIALOGUNITDESC_H

#include "DialogUnit.h"
#include "EventManager.h"
#include "ConsoleBlockDesc.h"
#include "MenuOption.h"

class DialogUnitDesc : public DialogUnit, public EventManager::Observer
{
    public:
        static const std::string FOCUS_NAME;
        struct OptionsMsg {
            int select;
            std::string title;
            std::string focusBackTo;
            void* focusBackMsg;
            std::vector<MenuOption> options;
            MenuOption::CBF cancelCBF;
            bool addCancel;
            std::string emptyMsg; // use when no option is given, default to "<No Actions>"
        };
        struct DescMsg {
            std::string title;
            std::vector<std::string> lines;
            DescMsg() {}
            DescMsg(const std::string& title, const std::vector<std::string> &lines)
                : title(title), lines(lines) {}
        };
        struct DrawMsg {
            bool show;
            int mode;
            OptionsMsg* opts;
            DescMsg* desc;
        };
        DialogUnitDesc();
        virtual ~DialogUnitDesc();

        virtual void onKeyPressed(InputCommand* cmd, Farm* farm);
        virtual void refresh(Farm* farm);
        virtual void submit();
        virtual int onEvent(const std::string &ev, void* msg);
    protected:

    private:
        DrawMsg draw;
        DescMsg dMsg;
        OptionsMsg oMsg;
        ConsoleBlockDesc cb;
        std::vector<OptionsMsg> oStack;
        void setFocus();
        void popBack(Farm *farm, int res);
        void showDesc();
        void showOpts();
};

#endif // DIALOGUNITDESC_H
