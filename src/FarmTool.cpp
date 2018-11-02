#include "FarmTool.h"
#include "GameDriverSingleton.h"

FarmTool::FarmTool()
{
    //ctor
}

FarmTool::~FarmTool()
{
    //dtor
}

//int FarmTool::actionWithRefresh(FarmField* target) {
//    int res = this->action(target);
//    GameDriverSingleton::getInstance()->getEventManager()
//        ->emit(GameDriver::Event::REFRESH_SCREEN, nullptr);
//    return res;
//}
