#ifndef __SLEEP_TIMER__
#define __SLEEP_TIMER__

#include "Timer.h"
#include "Task.h"
#include "LightSensorImpl.h"
#include "sonarImpl.h"

class SleepTimer: public Task{

public:
    SleepTimer();
    void init(int period);
    void tick();
private:
    int time;
    LightSensor* lightSensor;
    Sonar* sonar;
    int lightLevel;
    int lightIntensity;
    bool movement;
    double distance;
};