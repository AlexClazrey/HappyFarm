#ifndef FARMCLOCK_H
#define FARMCLOCK_H


class FarmClock
{
    public:
        FarmClock();
        virtual ~FarmClock();

        int getSeconds() const { return this->seconds; }
        void setSeconds(int seconds) { this->seconds = seconds; }
        void addSeconds(int seconds) { this->seconds += seconds; }
        void setPaused(bool p) { this->paused = p; }
        bool getPause() { return this->paused; }
    protected:

    private:
        int seconds;
        bool paused;
};

#endif // FARMCLOCK_H
