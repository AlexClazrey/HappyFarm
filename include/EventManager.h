#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <map>
#include <vector>
#include <string>

class EventManager
{
    public:
        class Observer {
            public:
                virtual int onEvent(const std::string& eventName, void* msg) = 0;
        };
        EventManager();
        virtual ~EventManager();
        EventManager* addObserver(const std::string& eventName, Observer* obs);
        EventManager* removeObserver(const std::string& eventName, Observer* obs);
        void emit(const std::string& eventName, void* msg);
    protected:
    private:
        std::map<std::string, std::vector<Observer*>> data;
};

#endif // EVENTMANAGER_H
