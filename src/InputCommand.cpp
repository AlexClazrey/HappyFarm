#include "InputCommand.h"

InputCommand::InputCommand() : keyPressed(InputCommand::Key::None), timestamp(std::chrono::system_clock::now())
{
    //ctor
}

InputCommand::InputCommand(Key key, decltype(std::chrono::system_clock::now()) timeNow) : keyPressed(key), timestamp(timeNow)
{
}

InputCommand::~InputCommand()
{
    //dtor
}
