#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "InputManager.h"
#include "GameDriverSingleton.h"

#include "DebugHeader.h"

const int InputManager::ReadKeyInterval = 100;
const int InputManager::TimeEventInterval = 1000;

InputManager::InputManager() : timeEventLeft(InputManager::TimeEventInterval), stopFlag(false)
{
}

void InputManager::start() {
    this->win = newwin(0, 0, 0, 0);
    noecho();
    cbreak();
    nodelay(this->win, true);

    int cycles = 0;
    int keyCount;
    char keys[10] = { 0 };
    // add stop event listener
    GameDriverSingleton::getInstance()->getEventManager()
        ->addObserver(GameDriver::Event::STOP_READ_INPUT, this)
        ->addObserver(GameDriver::Event::START_READ_INPUT, this);


    while(1)
    {
        if(this->stopFlag) {
            break;
        }
        cycles++;
        keyCount = 0;
        while(keyCount < 10 && (keys[keyCount++] = wgetch(this->win)) && keys[keyCount - 1] != EOF) {}; //read all key pressed
        keyCount--;
        if(keyCount > 0) {
            InputCommand::Key keyPressed = checkKey(keys, keyCount);
            InputCommand cmd(keyPressed, std::chrono::system_clock::now());
            // connect to outside world - 1
            GameDriverSingleton::getInstance()->getEventManager()->emit(GameDriver::Event::KEY_PRESSED, &cmd);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(InputManager::ReadKeyInterval));
        this->timeEventLeft -= InputManager::ReadKeyInterval;
        if(this->timeEventLeft < 0) {
            this->timeEventLeft = InputManager::TimeEventInterval;
            // Publish Time Event Here;
            auto timestamp = std::chrono::system_clock::now();
            GameDriverSingleton::getInstance()->getEventManager()
                ->emit(GameDriver::Event::TIME_PASSED, &timestamp);
        }
        refresh();
    }
}

void InputManager::exit() {
    this->stopFlag = true;
}

int InputManager::onEvent(const std::string& eventName, void* msg) {
    // connect to outside world - 2
    if(eventName == GameDriver::Event::STOP_READ_INPUT) {
        this->exit();
    } else if (eventName == GameDriver::Event::START_READ_INPUT) {
        this->start();
    }
    return 0;
}


InputCommand::Key InputManager::checkKey(char keys[], int keyCount) {
    #ifdef DEBUG_INPUT
    for(int i = 0; i < keyCount; i++) {
        addstr(std::to_string(keys[i]).c_str());
    }
    #endif // DEBUG_INPUT
    if(keyCount == 0)
        return InputCommand::Key::None;
    if(keyCount == 1) {
        switch(keys[0]) {
        case 'W':
        case 'w':
            return InputCommand::Key::W;
        case 'A':
        case 'a':
            return InputCommand::Key::A;
        case 'S':
        case 's':
            return InputCommand::Key::S;
        case 'D':
        case 'd':
            return InputCommand::Key::D;
        case 27:
            return InputCommand::Key::Esc;
        case '\n':
            return InputCommand::Key::Enter;
        case ' ':
            return InputCommand::Key::Space;
        case '\t':
            return InputCommand::Key::Tab;
        default:
            return InputCommand::Key::Other;
        }
    }
    if(keyCount == 3 and keys[1] == '[') {
    switch(keys[2]) {
        case 'A':
            return InputCommand::Key::Up;
        case 'B':
            return InputCommand::Key::Down;
        case 'C':
            return InputCommand::Key::Right;
        case 'D':
            return InputCommand::Key::Left;
        }
    }
    return InputCommand::Key::Other;
}

InputManager::~InputManager()
{
}
