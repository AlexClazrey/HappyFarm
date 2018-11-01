#include "GameDriverSingleton.h"

GameDriver* GameDriverSingleton::instance = nullptr;

GameDriverSingleton::GameDriverSingleton()
{
}

void GameDriverSingleton::startGame() {
    GameDriverSingleton::instance->startGame();
}

GameDriver* GameDriverSingleton::getInstance() {
    if(GameDriverSingleton::instance == nullptr) {
        GameDriverSingleton::instance = new GameDriver();
    }
    return GameDriverSingleton::instance;
}

void GameDriverSingleton::exit() {
    if(GameDriverSingleton::instance) {
        delete GameDriverSingleton::instance;
        GameDriverSingleton::instance = nullptr;
    }
}

GameDriverSingleton::~GameDriverSingleton()
{
    exit();
}
