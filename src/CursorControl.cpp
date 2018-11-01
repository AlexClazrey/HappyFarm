#include "CursorControl.h"

CursorControl::CursorControl() {
    this->isShow = true;
    this->winBorder = nullptr;
    this->panelBorder = nullptr;
    this->win = stdscr;
    this->startPoint = CCTL::PT(0, 0);
    getmaxyx(this->win, this->winSize.y, this->winSize.x);
}
CursorControl::CursorControl(const CCTL::PT &startPoint, const CCTL::PT &winSize)
    : startPoint(startPoint), winSize(winSize) {
    this->isShow = true;
    this->winBorder = nullptr;
    this->panelBorder = nullptr;
    this->win = newwin(winSize.y, winSize.x, startPoint.y, startPoint.x);
    this->panel = new_panel(this->win);
}
CursorControl::~CursorControl() {
    if(this->panel)
        del_panel(this->panel);
    if(this->panelBorder)
        del_panel(this->panelBorder);
    if(this->win)
        delwin(this->win);
    if(this->winBorder)
        delwin(this->winBorder);
}

CursorControl* CursorControl::clear() {
    if(this->win)
        wclear(this->win);
    if(this->winBorder)
        wclear(this->winBorder);
    return this;
}
CursorControl* CursorControl::clearMoveAndBorder() {
    this->clear();
    this->drawBorder();
    this->moveToTop();
    return this;
}
CursorControl* CursorControl::refresh() {
    if(this->winBorder)
        wrefresh(this->winBorder);
    if(this->win)
        wrefresh(this->win);
    return this;
}
CursorControl* CursorControl::borderOn() {
    this->border = true;
    this->winBorder = this->win;
    this->panelBorder = this->panel;
    this->win = newwin(winSize.y - 2, winSize.x - 2, startPoint.y + 1, startPoint.x + 1);
    this->panel = new_panel(this->win);
    return this;
}
CursorControl* CursorControl::borderOff() {
    this->border = false;
    del_panel(this->panel);
    delwin(this->win);
    this->panel = this->panelBorder;
    this->win = this->winBorder;
    this->panelBorder = nullptr;
    this->winBorder = nullptr;
    return this;
}
CursorControl* CursorControl::hide() {
     if(isShow) {
        if(panel)
            hide_panel(panel);
        if(panelBorder)
            hide_panel(panelBorder);
     }
     isShow = false;
     return this;
}
CursorControl* CursorControl::show() {
     if(isShow) {
        if(panelBorder)
            show_panel(panelBorder);
        if(panel)
            show_panel(panel);
     }
    isShow = true;
    return this;
}
CursorControl* CursorControl::top() {
    if(isShow) {
        if(panelBorder)
            top_panel(panelBorder);
        if(panel)
            top_panel(panel);
    }
    return this;
}
CursorControl* CursorControl::drawBorder() {
    if(this->winBorder)
        wborder(this->winBorder, 0, 0, 0, 0, 0, 0, 0, 0);
    return this;
}
CursorControl* CursorControl::attrOn(int attr) {
    if(this->win)
        wattron(this->win, attr);
    return this;
}
CursorControl* CursorControl::attrOff(int attr) {
    if(this->win)
        wattroff(this->win, attr);
    return this;
}
CursorControl* CursorControl::print(const char* str) {
    if(this->win)
        waddstr(this->win, str);
    return this;
}
CursorControl* CursorControl::print(const std::string &str) {
    return this->print(str.c_str());
}
CursorControl* CursorControl::print(const int input) {
    return this->print(std::to_string(input));
}
int CursorControl::getX() const {
    if(this->win) {
        int y,x;
        getyx(this->win, y, x);
        (void)y; // suppress unused variable warning
        return x;
    }
    return -1;
}
int CursorControl::getY() const {
    if(this->win) {
        int y,x;
        getyx(this->win, y, x);
        (void)x; // suppress unused variable warning
        return y;
    }
    return -1;
}
CursorControl* CursorControl::charTo(const int xPos, const char ch) {
    if(this->win) {
        int x = this->getX();
        int dist = xPos - x;
        while(dist-- > 0) {
            waddch(this->win, ch);
        }
    }
    return this;
}
CursorControl* CursorControl::spaceTo(const int xPos) {
    return this->charTo(xPos, ' ');
}
CursorControl* CursorControl::nextLine() {
    return this->print("\n");
}

CursorControl* CursorControl::moveTo(const PT& position) {
    if(this->win) {
        wmove(this->win, position.y, position.x);
    }
    return this;
}
CursorControl* CursorControl::moveToRelative(const PT& distance) {
    if(this->win) {
        int y,x;
        getyx(this->win, y, x);
        wmove(this->win, distance.y + y, distance.x + x);
    }
    return this;
}
CursorControl* CursorControl::moveToTop() {
    return this->moveTo(CCTL::PT(0,0));
}
CursorControl* CursorControl::moveToLineHead() {
    if(this->win) {
        int y,x;
        getyx(this->win, y, x);
        return this->moveTo(CCTL::PT(y, 0));
    }
    return this;
}

