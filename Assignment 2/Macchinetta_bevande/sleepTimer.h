#ifndef __SLEEPTIMER__
#define __SLEEPTIMER__

#include "Timer.h"
#include "Task.h"

class SleepTimer: public Task{

    int time;
public:
    SleepTimer();
    void init(int period);
    void tick();
private:
    
}