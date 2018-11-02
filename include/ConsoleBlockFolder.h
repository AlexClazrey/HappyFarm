#ifndef CONSOLEBLOCKFOLDER_H
#define CONSOLEBLOCKFOLDER_H

#include "ConsoleBlock.h"
#include <vector>

class ConsoleBlockFolder : public ConsoleBlock
{
    public:
        ConsoleBlockFolder();
        virtual ~ConsoleBlockFolder();

        virtual void drawAfterTop() {
            for(ConsoleBlock* cb : sub) {
                cb->top();
            }
        }
        virtual void drawContent(void* msg) {
            for(ConsoleBlock* cb : sub) {
                cb->drawContent(msg);
            }
        }
    protected:

    private:
        std::vector<ConsoleBlock*> sub;
};

#endif // CONSOLEBLOCKFOLDER_H
