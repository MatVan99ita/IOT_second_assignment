#ifndef __TASK_SERVO_ROTATE__
#define __TASK_SERVO_ROTATE__

#include "ServoTimer2.h"
#include "Task.h"

class TaskServoRotate: public Task
{
    int pin;
    ServoTimer2* servo;

public:
    TaskServoRotate(int pin);
    void init(int period);
    void tick();
};

TaskServoRotate::TaskServoRotate(int pin)
{
    this->pin = pin;
}

void TaskServoRotate::init(int period){
    Task::init(period);
    this->servo->attach(this->pin);
    //this->rotation_state = POS;
}

void TaskServoRotate::tick()
{
    for(int i = 0; i < 180; i++){
        this->servo->write(i);
    }
    for(int i = 180; i > 0; i--){
        this->servo->write(i);
    }
}


#endif