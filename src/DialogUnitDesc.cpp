#include "DialogUnitDesc.h"
#include "DialogManager.h"
#include "GameDriverSingleton.h"

const std::string DialogUnitDesc::FOCUS_NAME = "FOCUS_DESC";

DialogUnitDesc::DialogUnitDesc()
{
    this->draw.show = false;
    this->draw.mode = 1;
    this->draw.opts = &(this->oMsg);
    this->draw.desc = &(this->dMsg);
    this->draw.opts->select = 0;
    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::CHANGE_FOCUS, this)
        ->addObserver(GameDriver::Event::SET_OPTIONS_CHANGE_FOCUS, this)
        ->addObserver(GameDriver::Event::SET_DESC, this)
        ->addObserver(GameDriver::Event::SHOW_LOG_DESC, this);
}

DialogUnitDesc::~DialogUnitDesc()
{
}

void DialogUnitDesc::showDesc() {
    this->draw.mode = 1;
    this->submit();
}

void DialogUnitDesc::showOpts() {
    this->draw.mode = 2;
    this->setFocus();
}

void DialogUnitDesc::popBack(Farm *farm, int res) {
    if(res == 0) {
        this->oStack.clear();
        this->showDesc();
        GameDriverSingleton::getInstance()->changeFocus(this->oMsg.focusBackTo, farm, this->oMsg.focusBackMsg);
    } else if(res == 1) {
        if(this->oStack.size() > 0) {
            this->oMsg = oStack[oStack.size() - 1];
            oStack.pop_back();
            this->draw.mode = 2;
        } else {
            this->popBack(farm, 0);
        }
    } else if(res == 2) {
        // do nothing here
    }
}

void DialogUnitDesc::onKeyPressed(InputCommand* cmd, Farm* farm) {
    // up and down arrow to select option
    // up/down/enter/escape
    int count = this->oMsg.options.size(); // options size;

    if(cmd->getKeyPressed() == InputCommand::Up && oMsg.select > 0) {
        this->oMsg.select--;
    } else if(cmd->getKeyPressed() == InputCommand::Down && oMsg.select < (count - 1 + (oMsg.addCancel ? 1 : 0)) ) {
        this->oMsg.select++;
    } else if(cmd->getKeyPressed() == InputCommand::Enter) {
        if(this->oMsg.select >= 0 && this->oMsg.select < count && this->oMsg.options[this->oMsg.select].getCBF()) {
            int res = this->oMsg.options[this->oMsg.select].getCBF()();
            this->popBack(farm, res);
        } else if(count == 0 || (this->oMsg.select == count && oMsg.addCancel)) {
            int res = this->oMsg.cancelCBF ? this->oMsg.cancelCBF() : 1;
            this->popBack(farm, res);
        } else {
            GameDriverSingleton::getInstance()->addLog("[ERROR] no callback for this operation");
        }
    } else if(cmd->getKeyPressed() == InputCommand::Esc) {
        if(this->oMsg.cancelCBF) {
            int res = this->oMsg.cancelCBF();
            this->popBack(farm, res);
        } else {
            this->popBack(farm, 1);
        }
    }
    this->refresh(farm);
}

void DialogUnitDesc::refresh(Farm* farm) {
    this->submit();
}

void DialogUnitDesc::submit() {
    GameDriverSingleton::getInstance()
        ->addDraw(&this->cb, 0, &this->draw);
}

void DialogUnitDesc::setFocus() {
    GameDriverSingleton::getInstance()->getEventManager()
        ->emit(GameDriver::Event::SET_FOCUS, this);
    this->draw.show = true;
    this->submit();
}

int DialogUnitDesc::onEvent(const std::string &ev, void *msg) {
    if(ev == GameDriver::Event::CHANGE_FOCUS && ((DialogManager::ChangeFocusMsg*)msg)->name == this->FOCUS_NAME) {
        this->setFocus();
    } else if(ev == GameDriver::Event::SET_OPTIONS_CHANGE_FOCUS) {
        if(this->draw.mode == 2) {
            this->oStack.push_back(this->oMsg);
        }
        this->oMsg = *(DialogUnitDesc::OptionsMsg*)msg;
        this->showOpts();
    } else if(ev == GameDriver::Event::SHOW_LOG_DESC) {
        if(msg != nullptr) {
            this->draw.show = true;
        } else {
            this->draw.show = false;
        }
        this->submit();
    } else if(ev == GameDriver::Event::SET_DESC) {
        this->dMsg = *(DialogUnitDesc::DescMsg*)msg;
        // not display descriptions in options mode
        if(this->draw.mode == 1)
            this->showDesc();
    }
    return 0;
}
