#ifndef FARMTOOLBOX_H
#define FARMTOOLBOX_H
#include "FarmTool.h"
#include <vector>

class FarmToolbox
{
    public:
        FarmToolbox();
        virtual ~FarmToolbox();

        void availableOptions(std::vector<MenuOption> &dest, FarmField* field);
    protected:

    private:
        std::vector<FarmTool*> tools;
};

#endif // FARMTOOLBOX_H
