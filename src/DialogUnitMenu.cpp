#include "DialogUnitMenu.h"
#include "DrawCommand.h"
#include "GameDriverSingleton.h"
#include "DialogUnitField.h"
#include "FarmBuilderNew.h"

const std::string DialogUnitMenu::FOCUS_NAME = "DIALOG_MAIN_MENU";

DialogUnitMenu::DialogUnitMenu(): cb()
{
    // menu needs to display at the beginning, so its show is true, different from other DialogUnits
    this->msg.show = true;
    // initialize draw message
    this->msg.select = 0;
    this->msg.options.push_back(std::string("Start Game"));
    this->msg.options.push_back(std::string("Quit"));
    // listen to focus events
    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::CHANGE_FOCUS, this);
}

DialogUnitMenu::~DialogUnitMenu()
{
}

void DialogUnitMenu::submit() {
    GameDriverSingleton::getInstance()
        ->addDraw(&this->cb, 0, &this->msg);
}

void DialogUnitMenu::triggerNewGame() {
    // New Farm initialize
    GameDriverSingleton::getInstance()->getFarmManager()->buildFarm(FarmBuilderNew());
    // Hide Menu Window
    this->msg.show = false;
    this->submit();
    // Add Log
    GameDriverSingleton::getInstance()->addLog("Use arrow keys, enter, tab, and escape to play.");
    GameDriverSingleton::getInstance()->addLog("Press tab to switch between yard, backpack and shop,");
    GameDriverSingleton::getInstance()->addLog("enter to interact, escape to cancel interact."); /**< or open menu */
    //GameDriverSingleton::getInstance()->addLog("(Menu is not done yet)");

    // Start time
    GameDriverSingleton::getInstance()->getFarmManager()->setTimeRun();
    // Change focus to field
    DialogManager::ChangeFocusMsg focusMsg(DialogUnitField::FOCUS_NAME, GameDriverSingleton::getInstance()->getFarm(), nullptr);
    GameDriverSingleton::getInstance()->getEventManager()
        ->emit(GameDriver::Event::CHANGE_FOCUS, &focusMsg);
}

void DialogUnitMenu::triggerLoadGame() {
    // TODO load game
}

void DialogUnitMenu::triggerExitGame() {
    GameDriverSingleton::getInstance()->getEventManager()
        ->emit(GameDriver::Event::GAME_EXIT, nullptr);
}

void DialogUnitMenu::onKeyPressed(InputCommand* cmd, Farm* farm) {
    if(cmd->getKeyPressed() == cmd->Down && msg.select < 1) {
        msg.select++;
    } else if(cmd->getKeyPressed() == cmd->Up && msg.select > 0) {
        msg.select--;
    } else if(cmd->getKeyPressed() == cmd->Enter) {
        if(msg.select == 1) {
            this->triggerExitGame();
        } else if(msg.select == 0) {
            this->triggerNewGame();
        }
    }
    this->submit();
}

void DialogUnitMenu::refresh(Farm* farm) {
    this->submit();
}

int DialogUnitMenu::onEvent(const std::string& ev, void* msg) {
    if(ev == GameDriver::Event::CHANGE_FOCUS && ((DialogManager::ChangeFocusMsg*)msg)->name == this->FOCUS_NAME) {
        // tell DialogManager it's my show time
        GameDriverSingleton::getInstance()->getEventManager()
            ->emit(GameDriver::Event::SET_FOCUS, this);
        // show flag is on for display on the screen
        this->msg.show = true;
        // you need to use refresh here when there are some data changes in farm that you will use
        // in menu there is no data change so just submit
        this->submit();
    }
    return 0;
}
