#ifndef GAMEDRIVERSINGLETON_H
#define GAMEDRIVERSINGLETON_H
#include "GameDriver.h"

class GameDriverSingleton
{
    public:
        void startGame();
        static GameDriver* getInstance();
        static void exit();
    protected:
    private:
        GameDriverSingleton();
        GameDriverSingleton(GameDriverSingleton& old);
        const GameDriverSingleton &operator=(const GameDriverSingleton& old);
        ~GameDriverSingleton();

        static GameDriver *instance;
};

#endif // GAMEDRIVERSINGLETON_H
