#ifndef INPUTCOMMAND_H
#define INPUTCOMMAND_H
#include <chrono>

class InputCommand
{
    public:
        enum Key {
            None,
            Up,
            Down,
            Left,
            Right,
            W,
            A,
            S,
            D,
            Esc,
            Enter,
            Space,
            Tab,
            Other
        };
        InputCommand();
        InputCommand(Key key, decltype(std::chrono::system_clock::now()) timestamp);
        virtual ~InputCommand();
        Key getKeyPressed() { return this->keyPressed; }
    protected:

    private:
        Key keyPressed;
        decltype(std::chrono::system_clock::now()) timestamp;
};

#endif // INPUTCOMMAND_H
