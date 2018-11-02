#include "ConsoleBlock.h"

ConsoleBlock::ConsoleBlock() : cursor(), makeTop(true)
{
}
ConsoleBlock::ConsoleBlock(const CCTL::PT& startPt, const CCTL::PT& size) : cursor(startPt, size), makeTop(true)
{
}
ConsoleBlock::ConsoleBlock(const ConsoleBlock *parent, const CCTL::PT& startPt, const CCTL::PT& size)
    : cursor(parent->cursor.getLeftCorner() + startPt, size), makeTop(true)
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

