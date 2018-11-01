#include "DialogManager.h"
#include "GameDriver.h"
#include "GameDriverSingleton.h"
#include "DialogUnitMenu.h"
#include "DialogUnitTime.h"
#include "DialogUnitField.h"
#include "DialogUnitDesc.h"
#include "DialogUnitLog.h"
#include "DialogUnitShop.h"
#include "DialogUnitBackpack.h"
#include <assert.h>

DialogManager::DialogManager()
{
    //ctor
}

DialogManager::~DialogManager()
{
    for(DialogUnit *pdu : this->units) {
        delete pdu;
    }
    //dtor
}

int DialogManager::onEvent(const std::string &eventName, void* obj) {
    if(eventName == GameDriver::Event::KEY_PRESSED) {
        if(this->focused) {
            this->focused->onKeyPressed((InputCommand*)obj, GameDriverSingleton::getInstance()->getFarm());
        } else {
            addstr("key pressed but no dialog focused.\n");
        }
    } else if(eventName == GameDriver::Event::REFRESH_SCREEN) {
        this->refresh(GameDriverSingleton::getInstance()->getFarm());
    } else if(eventName == GameDriver::Event::SET_FOCUS) {
        this->setFocus((DialogUnit *)obj);
    }
    GameDriverSingleton::getInstance()->getEventManager()
        ->emit(GameDriver::Event::DRAW_EXECUTE, nullptr);
    return 0;
}

void DialogManager::start() {
    addstr("dialog manager start.\n");
    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::KEY_PRESSED, this)
        ->addObserver(GameDriver::Event::REFRESH_SCREEN, this)
        ->addObserver(GameDriver::Event::SET_FOCUS, this);

    // add units here
    this->units.push_back(new DialogUnitMenu());
    this->units.push_back(new DialogUnitTime());
    this->units.push_back(new DialogUnitField());
    this->units.push_back(new DialogUnitDesc());
    this->units.push_back(new DialogUnitLog());
    this->units.push_back(new DialogUnitShop());
    this->units.push_back(new DialogUnitBackpack());
    // set focus to main menu
    this->focused = this->units[0];
}

void DialogManager::exit() {
}

void DialogManager::refresh(Farm* farm) {
    for(DialogUnit *du : this->units) {
        du->refresh(farm);
    }
}
