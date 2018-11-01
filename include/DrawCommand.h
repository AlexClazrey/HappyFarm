#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H
#include "ConsoleBlock.h"

class DrawCommand
{
    public:
        DrawCommand();
        DrawCommand(ConsoleBlock* target, int layer, void* msg);
        virtual ~DrawCommand();

        ConsoleBlock* getTarget() { return target; }
        int getLayer() { return layer; }
        void* getMsg() { return msg; }

    protected:

    private:
        ConsoleBlock* target;
        int layer;
        void* msg;
};

#endif // DRAWCOMMAND_H
