#include <iostream>
#include "GameDriverSingleton.h"

using namespace std;

int main()
{
    GameDriverSingleton::getInstance()->startGame();
    return 0;
}
