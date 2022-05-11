#ifndef __SLEEP_TIMER__
#define __SLEEP_TIMER__

#include "Timer.h"
#include "Task.h"
#include "LightSensorImpl.h"
#include "sonarImpl.h"
//#include "lcd_l2c.h"

class SleepTimer: public Task{

public:
    SleepTimer();
    void init(int period);
    void tick();
private:
    int time;
    LightSensor* lightSensor;
    SonarImpl* sonar;
    int lightLevel;
    int lightIntensity;
    bool movement;
    double distance;
    //lcd_l2c* l2c;
};

#endif
