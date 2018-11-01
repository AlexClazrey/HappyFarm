#include "DialogUnitLog.h"
#include "GameDriverSingleton.h"

DialogUnitLog::DialogUnitLog()
{
    this->draw.show = false;

    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::ADD_LOG, this)
        ->addObserver(GameDriver::Event::SHOW_LOG_DESC, this);
}

DialogUnitLog::~DialogUnitLog()
{
}

void DialogUnitLog::onKeyPressed(InputCommand* cmd, Farm* farm) {
    this->submit();
}
void DialogUnitLog::refresh(Farm *farm) {
    this->submit();
}
void DialogUnitLog::submit() {
    static const int LogSize = 8;
    if(history.size() < LogSize)
        draw.logs = std::vector<std::string>(history.begin(), history.end());
    else
        draw.logs = std::vector<std::string>(history.end() - LogSize, history.end()); // 这个减号居然是没有边界检查的直接段错误
    GameDriverSingleton::getInstance()->addDraw(&this->cb, 0, &this->draw);
}

int DialogUnitLog::onEvent(const std::string& eventName, void* msg) {
    if(eventName == GameDriver::Event::ADD_LOG) {
        history.push_back(*(std::string*)msg);
        this->submit();
    } if (eventName == GameDriver::Event::SHOW_LOG_DESC) {
        if(msg == nullptr) {
            draw.show = false;
        } else {
            draw.show = true;
        }
        this->submit();
    }
    return 0;
}
