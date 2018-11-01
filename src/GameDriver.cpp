#include "GameDriver.h"
#include "DrawCommand.h"
#include "DialogUnitDesc.h"

const std::string
    GameDriver::Event::GAME_EXIT = "GAME_EXIT",
    GameDriver::Event::START_READ_INPUT = "START_INPUT",
    GameDriver::Event::STOP_READ_INPUT = "STOP_INPUT",
    GameDriver::Event::KEY_PRESSED = "KEY_PRESSES",
    GameDriver::Event::TIME_PASSED = "TIME_PASSED",
    GameDriver::Event::FARM_UPDATE = "FARM_UPDATE",
    GameDriver::Event::REFRESH_SCREEN = "REFRESH_SCREEN",
    GameDriver::Event::DRAW_ADD = "DRAW_ADD",
    GameDriver::Event::DRAW_EXECUTE = "DRAW_EXE",
    GameDriver::Event::CHANGE_FOCUS = "CHANGE_FOCUS",
    GameDriver::Event::SET_FOCUS = "SET_FOCUS",
    GameDriver::Event::SET_DESC = "SET_DESC",
    GameDriver::Event::SET_OPTIONS_CHANGE_FOCUS = "SET_OPTIONS_CHANGE_FOCUS",
    GameDriver::Event::SHOW_LOG_DESC = "SHOW_LOG_DESC",
    GameDriver::Event::ADD_LOG = "ADD_LOG",
    GameDriver::Event::COMMIT_FARM_COMMAND = "COMMIT_FARM_COMMAND";

GameDriver::GameDriver()
{
    //ctor
}

void GameDriver::startGame() {
    this->publisher.addObserver(GameDriver::Event::GAME_EXIT, this);
    this->display.start();
    this->model.start();
    this->controller.start();
    this->inputs.start();
}

void GameDriver::exitGame() {
    this->inputs.exit();
    this->controller.exit();
    this->model.exit();
    this->display.exit();
}

void GameDriver::addDraw(ConsoleBlock* target, int layer, void* msg) {
    this->getEventManager()->emit(GameDriver::Event::DRAW_ADD, new DrawCommand(target, layer, msg));
}

// TODO reduce memory copy
void GameDriver::setDesc(const std::string &title, const std::vector<std::string> &lines) {
    DialogUnitDesc::DescMsg msg(title, lines);
    this->getEventManager()->emit(GameDriver::Event::SET_DESC, &msg);
}

void GameDriver::addLog(const std::string &log) {
    std::string tmp = log; //TODO reduce copy;
    this->getEventManager()->emit(GameDriver::Event::ADD_LOG, &tmp);
}

void GameDriver::changeFocus(const std::string &target, Farm* farm, void* msg) {
    auto fMsg = DialogManager::ChangeFocusMsg(target, farm, msg);
    this->getEventManager()->emit(GameDriver::Event::CHANGE_FOCUS, &fMsg);
}

void GameDriver::toMenuPage(DialogUnitDesc::OptionsMsg* msg) {
    this->getEventManager()->emit(GameDriver::Event::SET_OPTIONS_CHANGE_FOCUS, msg);
}

void GameDriver::commitFarmCommand(FarmCommand *cmd) {
    this->getEventManager()->emit(GameDriver::Event::COMMIT_FARM_COMMAND, cmd);
}

int GameDriver::onEvent(const std::string& ev, void* msg) {
    if(ev == GameDriver::Event::GAME_EXIT) {
        this->exitGame();
    }
    return 0;
}

GameDriver::~GameDriver()
{
    //dtor
}
