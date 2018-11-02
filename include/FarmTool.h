#ifndef FARMTOOL_H
#define FARMTOOL_H
#include <string>
#include "MenuOption.h"

class FarmField;
class FarmTool
{
    public:
        FarmTool();
        virtual ~FarmTool();
        virtual std::string getName() = 0;
        virtual std::string getDesc() = 0;
        virtual bool available(FarmField* target) = 0;
        virtual int action(FarmField *target) = 0;
        virtual MenuOption::CBF getCallback(FarmField *target) { return std::bind(&FarmTool::action, this, target); }
    protected:
        // virtual int actionWithRefresh(FarmField* target);
    private:
};

#endif // FARMTOOL_H
