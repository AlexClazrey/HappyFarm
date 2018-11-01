#ifndef DIALOGUNIT_H
#define DIALOGUNIT_H

class InputCommand;
class Farm;
class DialogUnit
{
    public:
        DialogUnit();
        virtual ~DialogUnit();
        virtual void onKeyPressed(InputCommand* cmd, Farm* farm) = 0;
        virtual void refresh(Farm* farm) = 0;
        virtual void submit() = 0;
    protected:

    private:
};

#endif // DIALOGUNIT_H
