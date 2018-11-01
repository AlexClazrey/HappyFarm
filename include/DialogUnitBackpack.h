#ifndef DIALOGUNITBACKPACK_H
#define DIALOGUNITBACKPACK_H

#include "DialogUnit.h"
#include "EventManager.h"
#include "ConsoleBlockBackpack.h"
#include "FarmItem.h"

class FarmPack;
class DialogUnitBackpack : public DialogUnit, public EventManager::Observer
{
    public:
        static const std::string FOCUS_NAME;
        struct DrawMsg {
            bool show;
            int select;
            int time;
            int money;
            std::vector<std::string> goods;
        };
        DialogUnitBackpack();
        virtual ~DialogUnitBackpack();

        virtual void onKeyPressed(InputCommand* cmd, Farm* farm);
        virtual void refresh(Farm* farm);
        virtual void submit();
        virtual int onEvent(const std::string& name, void* msg);
    protected:

    private:
        DrawMsg msg;
        ConsoleBlockBackpack cb;
        std::vector<FarmItem*> goodsList;
        static bool isGoods(const FarmItem*);
        void makeGoodsList(FarmPack* fp);
        void makeDesc();
        int sellConfirm(FarmItem::Code code, int amount, Farm *farm);
        static int sellCancel() { return 0; }
};

#endif // DIALOGUNITBACKPACK_H
