#ifndef __SLEEP_TIMER__
#define __SLEEP_TIMER__

#include "Timer.h"
#include "Task.h"

class SleepTimer: public Task{

public:
    SleepTimer();
    void init(int period);
    void tick();
private:
    int time;
};