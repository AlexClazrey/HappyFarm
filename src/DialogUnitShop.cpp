#include "DialogUnitShop.h"
#include "GameDriverSingleton.h"
#include "DialogUnitField.h"
#include <functional>
#include <algorithm>

const std::string DialogUnitShop::FOCUS_NAME = "FOCUS_SHOP";

DialogUnitShop::DialogUnitShop()
{
    this->msg.show = false;
    this->msg.select = 0;

    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::CHANGE_FOCUS, this);
}

DialogUnitShop::~DialogUnitShop()
{
}

void DialogUnitShop::onKeyPressed(InputCommand* cmd, Farm* farm) {
    this->makeGoodsList(&farm->pack);
    if(cmd->getKeyPressed() == InputCommand::Down && msg.select < (int)msg.goods.size() - 1) {
        msg.select++;
        this->makeDesc();
    } else if(cmd->getKeyPressed() == InputCommand::Up && msg.select > 0) {
        msg.select--;
        this->makeDesc();
    } else if(cmd->getKeyPressed() == InputCommand::Enter) {
        FarmItem::Code code = codeList[msg.select];
        if(farm->money >= farm->pack.getItem(code)->getBuyPrice()) {
            DialogUnitDesc::OptionsMsg res;
            res.cancelCBF = nullptr;
            res.focusBackTo = this->FOCUS_NAME;
            res.focusBackMsg = nullptr;
            res.select = 0;
            res.title = "Confirm to buy";
            res.options.push_back(MenuOption("Confirm", "I'll take it.", std::bind(DialogUnitShop::BuyConfirm, code, farm)));
            res.options.push_back(MenuOption("Cancel", "Wait...", std::function<int()>(DialogUnitShop::BuyCancel)));
            res.addCancel = false;
            GameDriverSingleton::getInstance()->toMenuPage(&res);
        } else {
            GameDriverSingleton::getInstance()->addLog("\"No money no goods.\" -Boss");
        }
    } else if(cmd->getKeyPressed() == InputCommand::Tab) {
        this->msg.show = 0;
        // this->submit();
        GameDriverSingleton::getInstance()->changeFocus(DialogUnitField::FOCUS_NAME, farm, nullptr);
    }
    this->submit();
}

void DialogUnitShop::refresh(Farm *farm) {
    if(farm) {
        this->makeGoodsList(&farm->pack);
        this->makeDesc();
        this->submit();
    }
}

void DialogUnitShop::submit() {
    // read money and time
    this->msg.money = GameDriverSingleton::getInstance()->getFarmManager()->getMoney();
    this->msg.time = GameDriverSingleton::getInstance()->getFarmManager()->getSecond();
    GameDriverSingleton::getInstance()->addDraw(&this->cb, 0, &this->msg);
}

int DialogUnitShop::onEvent(const std::string& ev, void* msg) {
    if(ev == GameDriver::Event::CHANGE_FOCUS && ((DialogManager::ChangeFocusMsg*)msg)->name == this->FOCUS_NAME) {
        GameDriverSingleton::getInstance()->getEventManager()
            ->emit(GameDriver::Event::SET_FOCUS, this);
        this->msg.show = 1;
        this->refresh(((DialogManager::ChangeFocusMsg*)msg)->farm);
    }
    return 0;
}

bool DialogUnitShop::isGoods(const FarmItem *pItem) {
    return pItem->getBuyPrice() > 0;
}

void DialogUnitShop::makeGoodsList(FarmPack* fp) {
    msg.goods.clear();
    codeList.clear();
    std::vector<FarmItem*> goods = fp->scanPack(std::function<bool(const FarmItem*)>(DialogUnitShop::isGoods));
    for(FarmItem *pItem : goods) {
        msg.goods.push_back(pItem->getName() + "\t[$" + std::to_string(pItem->getBuyPrice()) + "]\t[You have " + std::to_string(pItem->getCount()) + " now]");
        codeList.push_back(pItem->getCode());
    }
}

void DialogUnitShop::makeDesc() {
    // TODO description maker
}

int DialogUnitShop::BuyConfirm(FarmItem::Code code, Farm *farm) {
    FarmItem* pItem = farm->pack.getItem(code);
    farm->pack.addItem(code);
    farm->money -= pItem->getBuyPrice();
    GameDriverSingleton::getInstance()->addLog("You bought " + pItem->getName() + " for $" + std::to_string(pItem->getBuyPrice()) + ".");
    return 0;
}

