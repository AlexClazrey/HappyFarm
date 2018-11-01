#include "DrawCommand.h"

DrawCommand::DrawCommand()
{
}

DrawCommand::~DrawCommand()
{
}

DrawCommand::DrawCommand(ConsoleBlock *tar, int lay, void* msg) : target(tar), layer(lay), msg(msg)
{
}
