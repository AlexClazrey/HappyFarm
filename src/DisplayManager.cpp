#include "DisplayManager.h"
#include "GameDriverSingleton.h"
#include <algorithm>
#include <panel.h>

DisplayManager::DisplayManager()
{
}

void DisplayManager::start() {
    // libncurses initialize
    initscr();
    // Event subscribe
    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::DRAW_ADD, this)
        ->addObserver(GameDriver::Event::DRAW_EXECUTE, this);
}

void DisplayManager::exit() {
    endwin();
}

bool DisplayManager::compareCommand(DrawCommand* pt1, DrawCommand* pt2) {
    return pt1->getLayer() < pt2->getLayer();
}

int DisplayManager::onEvent(const std::string& eventName, void* obj) {
    if(eventName == GameDriver::Event::DRAW_ADD) {
        // add to paint list
        this->drawList.push_back((DrawCommand*)obj);
    } else if (eventName == GameDriver::Event::DRAW_EXECUTE) {
        // sort by image layer and paint
        std::sort(this->drawList.begin(), this->drawList.end(), DisplayManager::compareCommand);
        for(DrawCommand* cmd : this->drawList) {
            cmd->getTarget()->drawAll(cmd->getMsg());
            delete cmd;
        }
        this->drawList.clear();
        update_panels();
        doupdate();
    }
    return 0;
}

DisplayManager::~DisplayManager()
{
}
