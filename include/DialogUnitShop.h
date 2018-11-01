#ifndef DIALOGUNITSHOP_H
#define DIALOGUNITSHOP_H

#include "DialogUnit.h"
#include "ConsoleBlockShop.h"
#include "FarmItem.h"
#include "FarmPack.h"
#include "EventManager.h"

class DialogUnitShop : public DialogUnit, public EventManager::Observer
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
        DialogUnitShop();
        virtual ~DialogUnitShop();

        virtual void onKeyPressed(InputCommand* cmd, Farm* farm);
        virtual void refresh(Farm* farm);
        virtual void submit();

        virtual int onEvent(const std::string& ev, void* msg);
    protected:

    private:
        DrawMsg msg;
        ConsoleBlockShop cb;
        std::vector<FarmItem::Code> codeList;
        static bool isGoods(const FarmItem*);
        void makeGoodsList(FarmPack* fp);
        void makeDesc();
        static int BuyConfirm(FarmItem::Code code, Farm *farm);
        static int BuyCancel() { return 0; }
};

#endif // DIALOGUNITSHOP_H
