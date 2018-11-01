#include "DialogUnitTime.h"
#include "GameDriverSingleton.h"
#include <iostream>
#include <fstream>
DialogUnitTime::DialogUnitTime()
{
    this->kickoff = false;
    this->time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::TIME_PASSED, this);
}

DialogUnitTime::~DialogUnitTime()
{
    //dtor
}

void DialogUnitTime::onKeyPressed(InputCommand* cmd, Farm* farm) {}
void DialogUnitTime::refresh(Farm* farm) {}
void DialogUnitTime::submit() {}

int DialogUnitTime::onEvent(const std::string& eventName, void* msg) {
    if(eventName == GameDriver::Event::TIME_PASSED) {
        // message should be time distance
        auto clock = (decltype(std::chrono::system_clock::now())*)msg;
        int timeNow = std::chrono::system_clock::to_time_t(*clock);
        int diff = timeNow - this->time;
        this->time = timeNow;
        // check if farm time is running not paused
        if(!GameDriverSingleton::getInstance()->getFarmManager()->isPaused()) {
            GameDriverSingleton::getInstance()->getEventManager()
                ->emit(GameDriver::Event::FARM_UPDATE, &diff);
        }
        if(!this->kickoff) {
            // event for game start-up
            this->kickoff = true;
            GameDriverSingleton::getInstance()->getEventManager()
                ->emit(GameDriver::Event::REFRESH_SCREEN, nullptr);
        }
    }
    return 0;
}
