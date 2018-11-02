#include "DialogUnitField.h"
#include "DialogManager.h"
#include "GameDriverSingleton.h"
#include "DescriptionMaker.h"
#include "DialogUnitShop.h"
#include "DialogUnitBackpack.h"

const std::string DialogUnitField::FOCUS_NAME = "FOCUS_FIELD";

DialogUnitField::DialogUnitField()
{
    this->msg.show = false;
    this->msg.select = 0;
    this->msg.selectOnField = true;

    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::CHANGE_FOCUS, this);
}

DialogUnitField::~DialogUnitField()
{
}

void DialogUnitField::makeSummary(Farm *farm) {
    this->msg.fields.clear();
    // debug for an hour to found this can be null then yard is 0x10
    if(farm)
        farm->yard.makeSummary(this->msg.fields);
}

void DialogUnitField::makeDesc(Farm* farm) {
    if(this->msg.selectOnField && farm) {
         std::vector<std::string>* lines = DescriptionMaker::makeField(farm->yard.getField(this->msg.select));
         std::string title = (*lines)[lines->size() - 1];
         lines->pop_back();
         GameDriverSingleton::getInstance()->setDesc(title, *lines);
         delete lines;
    }
}

void DialogUnitField::openFieldMenu(FarmField *field, Farm* farm) {
    if(farm && field) {
        DialogUnitDesc::OptionsMsg res;
        res.cancelCBF = nullptr;
        res.focusBackTo = DialogUnitField::FOCUS_NAME;
        res.focusBackMsg = nullptr;
        res.select = 0;
        res.title = field->descriptionTitle() + " Actions";
        farm->toolbox.availableOptions(res.options, field);
        if(res.options.size() > 0) {
            res.addCancel = true;
        } else {
            res.addCancel = false;
        }
        GameDriverSingleton::getInstance()->toMenuPage(&res);
    }
}

void DialogUnitField::onKeyPressed(InputCommand* cmd, Farm* farm) {
    // up/down/enter/tab/escape five keys
    bool lastSubmit = true;
    this->makeSummary(farm);
    // select on land
    if(cmd->getKeyPressed() == InputCommand::Down && this->msg.select < fieldSize() - 1) {
        this->msg.select++;
        this->makeDesc(farm);
    } else if (cmd->getKeyPressed() == InputCommand::Up && this->msg.select > 0) {
        this->msg.select--;
        this->makeDesc(farm);
    } else if (cmd->getKeyPressed() == InputCommand::Enter) {
        if(msg.select >= 0 && msg.select < fieldSize()) {
            openFieldMenu(farm->yard.getField(msg.select), farm);
        }
    } else if (cmd->getKeyPressed() == InputCommand::Tab) {
        this->msg.show = 0;
        this->submit(); // place this here can prevent bug, now i know because top and hide issue
        lastSubmit = false;
        // GameDriverSingleton::getInstance()->addLog("Tab pressed");
        GameDriverSingleton::getInstance()->changeFocus(DialogUnitBackpack::FOCUS_NAME, farm, nullptr);
    }
    if(lastSubmit)
        this->submit();
}

void DialogUnitField::refresh(Farm* farm) {
    this->makeDesc(farm);
    this->makeSummary(farm);
    this->submit();
}

void DialogUnitField::submit() {
    // read money and time
    this->msg.money = GameDriverSingleton::getInstance()->getFarmManager()->getMoney();
    this->msg.time = GameDriverSingleton::getInstance()->getFarmManager()->getSecond();
    GameDriverSingleton::getInstance()->addDraw(&this->cb, 0, &this->msg);
}

int DialogUnitField::onEvent(const std::string& ev, void* obj) {
    if(ev == GameDriver::Event::CHANGE_FOCUS && ((DialogManager::ChangeFocusMsg*)obj)->name == this->FOCUS_NAME) {
        GameDriverSingleton::getInstance()->getEventManager()
            ->emit(GameDriver::Event::SET_FOCUS, this);
        GameDriverSingleton::getInstance()->getEventManager()
            ->emit(GameDriver::Event::SHOW_LOG_DESC, (void*)1);
        this->msg.show = 1;
        this->refresh(((DialogManager::ChangeFocusMsg*)obj)->farm);
    }
    return 0;
}
