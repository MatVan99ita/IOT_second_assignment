#include "sleepTimer.h"

SleepTimer::SleepTimer(){
    
}

void SleepTimer::init(int period){
    Task::init(period);
}

void SleepTimer::tick(){
}
