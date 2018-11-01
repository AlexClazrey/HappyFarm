#include "EventManager.h"

EventManager::EventManager()
{
    //ctor
}

EventManager::~EventManager()
{
    //dtor
}

EventManager* EventManager::addObserver(const std::string& eventName, Observer* obs) {
    auto it = this->data.find(eventName);
    if(it == this->data.end()) {
        std::vector<Observer*> vecObs;
        vecObs.push_back(obs);
        this->data.emplace(eventName, vecObs);
    } else {
        // no duplicate check now
        it->second.push_back(obs);
    }
    return this;
}

void EventManager::emit(const std::string& eventName, void* msg) {
    auto it = this->data.find(eventName);
    if(it != this->data.end()) {
        for(Observer* obs : it->second) {
            obs->onEvent(eventName, msg);
        }
    }
}
