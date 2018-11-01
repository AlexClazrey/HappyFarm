#include "ConsoleBlock.h"

ConsoleBlock::ConsoleBlock() : cursor()
{
}
ConsoleBlock::ConsoleBlock(const CCTL::PT& startPt, const CCTL::PT& size) : cursor(startPt, size)
{
}
ConsoleBlock::~ConsoleBlock()
{
}

void ConsoleBlock::drawAll(void* msg) {
    this->cursor.clearMoveAndBorder();
    this->drawContent(msg);
    this->cursor.top();
}

