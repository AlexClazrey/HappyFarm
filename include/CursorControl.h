#ifndef CURSORCONTROL_H
#define CURSORCONTROL_H
#include <ncurses.h>
#include <panel.h>
#include <string>

class CursorControl
{
public:
    struct Point {
        int x;
        int y;
        Point() : x(0), y(0) {}
        Point(int x, int y) : x(x), y(y) {};
        Point operator+(const Point& op1) { return Point(op1.x + x, op1.y + y); }
    };
    typedef Point PT;

    CursorControl();
    CursorControl(const PT &startPoint, const PT &winSize);
    virtual ~CursorControl();

    CursorControl* clear();
    CursorControl* clearMoveAndBorder();
    CursorControl* refresh();
    CursorControl* drawBorder();
    CursorControl* borderOn();
    CursorControl* borderOff();
    bool hasBorder() { return this->border; }
    int getX() const;
    int getY() const;
    int getSizeX() const { return winSize.x; }
    int getSizeY() const { return winSize.y; }
    PT getSize() const { return winSize; }
    PT getLeftCorner() const { return border ? PT(1,1) + startPoint : startPoint; }
    CursorControl* hide();
    CursorControl* show();
    CursorControl* top();
    CursorControl* above(CursorControl*);
    CursorControl* attrOn(int attr);
    CursorControl* attrOff(int attr);
    CursorControl* print(const std::string& str);
    CursorControl* print(const char* str);
    CursorControl* print(const int input);
    CursorControl* charTo(const int xPos, const char ch1);
    CursorControl* spaceTo(const int xPos);
    CursorControl* nextLine();
    CursorControl* moveTo(const PT& position);
    CursorControl* moveToRelative(const PT& distance);
    CursorControl* moveToTop();
    CursorControl* moveToLineHead();
protected:
private:
    bool border;
    bool isShow;
    PT startPoint;
    PT winSize;
    WINDOW *win, *winBorder;
    PANEL *panel, *panelBorder;
};
typedef CursorControl CCTL;


#endif // CURSORCONTROL_H
