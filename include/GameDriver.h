#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H
#include <string>
#include "DisplayManager.h"
#include "InputManager.h"
#include "EventManager.h"
#include "FarmManager.h"
#include "DialogManager.h"
#include "DialogUnitDesc.h"

class GameDriver : public EventManager::Observer
{
    public:
        class Event {
            public:
                static const std::string
                    GAME_EXIT,
                    START_READ_INPUT,
                    STOP_READ_INPUT,
                    KEY_PRESSED,
                    TIME_PASSED,
                    FARM_UPDATE,
                    REFRESH_SCREEN,
                    DRAW_ADD,
                    DRAW_EXECUTE,
                    CHANGE_FOCUS,
                    SET_FOCUS,
                    SET_DESC,
                    SET_OPTIONS_CHANGE_FOCUS,
                    SHOW_LOG_DESC,
                    ADD_LOG,
                    COMMIT_FARM_COMMAND;
        };
        GameDriver();
        virtual ~GameDriver();
        void startGame();
        void exitGame();

        EventManager* getEventManager() { return &this->publisher; }
        FarmManager* getFarmManager() { return &this->model; }
        Farm* getFarm() { return this->getFarmManager()->getFarm(); }
        //DisplayManager* getDisplayManager() { return &this->display; }

        void addDraw(ConsoleBlock* target, int layer, void* msg);
        void setDesc(const std::string &title, const std::vector<std::string> &lines);
        void addLog(const std::string &log);
        void changeFocus(const std::string &target, Farm* farm, void* msg);
        void toMenuPage(DialogUnitDesc::OptionsMsg* msg);
        void commitFarmCommand(FarmCommand *cmd);
        int getFarmClock() { return model.getSecond(); }
        void addItem(FarmItem::Code code, int count) {
            model.getFarm()->pack.addItem(code, count);
        }
        void removeItem(FarmItem::Code code, int count) {
            model.getFarm()->pack.removeItem(code, count);
        }
        virtual int onEvent(const std::string& ev, void* msg);
    protected:

    private:
        DisplayManager display;
        FarmManager model;
        DialogManager controller;
        InputManager inputs;
        EventManager publisher;
};

#endif // GAMEDRIVER_H
