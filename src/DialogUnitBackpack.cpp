#include "DialogUnitBackpack.h"
#include "GameDriverSingleton.h"
#include "FarmPack.h"
#include "DialogUnitField.h"
#include "DialogUnitShop.h"
#include <functional>


const std::string DialogUnitBackpack::FOCUS_NAME = "FOCUS_BACKPACK";

DialogUnitBackpack::DialogUnitBackpack()
{
    this->msg.show = false;
    this->msg.select = 0;

    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::CHANGE_FOCUS, this);
}

DialogUnitBackpack::~DialogUnitBackpack()
{
}

DialogUnitBackpack::onEvent(const std::string& name, void* msg) {
    if(name == GameDriver::Event::CHANGE_FOCUS && ((DialogManager::ChangeFocusMsg*)msg)->name == this->FOCUS_NAME) {
        GameDriverSingleton::getInstance()->getEventManager()
            ->emit(GameDriver::Event::SET_FOCUS, this);
        this->msg.show = 1;
        this->refresh(((DialogManager::ChangeFocusMsg*)msg)->farm);
    }
    return 0;
}

void DialogUnitBackpack::onKeyPressed(InputCommand* cmd, Farm* farm) {
    bool lastSubmit = true;
    this->makeGoodsList(&farm->pack);
    if(cmd->getKeyPressed() == InputCommand::Down && msg.select < (int)msg.goods.size() - 1) {
        msg.select++;
        this->makeDesc();
    } else if(cmd->getKeyPressed() == InputCommand::Up && msg.select > 0) {
        msg.select--;
        this->makeDesc();
    } else if(cmd->getKeyPressed() == InputCommand::Enter) {
        FarmItem::Code code = goodsList[msg.select]->getCode();
        DialogUnitDesc::OptionsMsg res;
        res.cancelCBF = nullptr;
        res.focusBackTo = this->FOCUS_NAME;
        res.focusBackMsg = nullptr;
        res.select = 0;
        res.title = "Confirm to sell";
        res.options.push_back(MenuOption("Sell One", "Cash, please.", std::bind(&DialogUnitBackpack::sellConfirm, this, code, 1, farm)));
        res.options.push_back(MenuOption("Sell All", "I need a bundle of them.", std::bind(&DialogUnitBackpack::sellConfirm, this, code, goodsList[msg.select]->getCount(), farm)));
        res.options.push_back(MenuOption("Cancel", "Wait...", std::function<int()>(DialogUnitBackpack::sellCancel)));
        res.addCancel = false;
        GameDriverSingleton::getInstance()->toMenuPage(&res);
    } else if(cmd->getKeyPressed() == InputCommand::Tab) {
        this->msg.show = 0;
        this->submit();
        lastSubmit = false;
        GameDriverSingleton::getInstance()->changeFocus(DialogUnitShop::FOCUS_NAME, farm, nullptr);
    }
    if(lastSubmit)
        this->submit();
}

void DialogUnitBackpack::refresh(Farm* farm) {
    if(farm) {
        this->makeGoodsList(&farm->pack);
        this->makeDesc();
        this->submit();
    }
}

void DialogUnitBackpack::submit() {
    // read money and time
    this->msg.money = GameDriverSingleton::getInstance()->getFarmManager()->getMoney();
    this->msg.time = GameDriverSingleton::getInstance()->getFarmManager()->getSecond();
    GameDriverSingleton::getInstance()->addDraw(&this->cb, 0, &this->msg);
}

int DialogUnitBackpack::sellConfirm(FarmItem::Code code, int amount, Farm* farm) {
    farm->pack.removeItem(code, amount);
    farm->money += farm->pack.getItem(code)->getSoldPrice() * amount;
    this->msg.select = 0;
    return 0;
}

bool DialogUnitBackpack::isGoods(const FarmItem *pItem) {
    return pItem->getCount() > 0;
}

void DialogUnitBackpack::makeGoodsList(FarmPack* fp) {
    msg.goods.clear();
    goodsList.clear();
    std::vector<FarmItem*> goods = fp->scanPack(std::function<bool(const FarmItem*)>(DialogUnitBackpack::isGoods));
    for(FarmItem *pItem : goods) {
        msg.goods.push_back(pItem->getName() + "\t[x" + std::to_string(pItem->getCount()) + "]\t[$" + std::to_string(pItem->getSoldPrice()) + "]");
        goodsList.push_back(pItem);
    }
}

void DialogUnitBackpack::makeDesc() {
    //TODO
}
