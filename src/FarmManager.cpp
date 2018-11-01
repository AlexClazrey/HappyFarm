#include "FarmManager.h"
#include "GameDriverSingleton.h"
#include <assert.h>
#include <string>

FarmManager::FarmManager() {
}

FarmManager::~FarmManager() {
    if(myFarm)
        delete myFarm;
}

void FarmManager::start() {
    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::FARM_UPDATE, this)
        ->addObserver(GameDriver::Event::COMMIT_FARM_COMMAND, this);
}

void FarmManager::exit() {
}

int FarmManager::onEvent(const std::string& eventName, void* msg) {
    if(eventName == GameDriver::Event::FARM_UPDATE) {
        // msg is seconds diff
        int diff = *(int*)msg;
        this->myFarm->clock.addSeconds(diff);
        // pass time to farm to refresh
        while(diff-- > 0) {
            myFarm->yard.update();
        }
        GameDriverSingleton::getInstance()->getEventManager()
            ->emit(GameDriver::Event::REFRESH_SCREEN, nullptr);
    } else if(eventName == GameDriver::Event::COMMIT_FARM_COMMAND) {
        int res = myFarm->executeCommand((FarmCommand*)msg);
        if(res) {
            GameDriverSingleton::getInstance()->addLog("FarmCommandResult: " + std::to_string(res));
        }
    }
    return 0;
}

void FarmManager::buildFarm(const FarmBuilder& builder) {
    if(myFarm) {
        delete myFarm;
    }
    myFarm = builder.buildFarm();
}
//
//void FarmManager::makeYardSummary(std::vector<std::string>&dest) {
//    this->myFarm->yard.makeSummary(dest);
//}
