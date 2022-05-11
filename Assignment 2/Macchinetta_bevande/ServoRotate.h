#ifndef __TASK_SERVO_ROTATE__
#define __TASK_SERVO_ROTATE__

#include "ServoTimer2.h"
#include "Task.h"

class ServoRotate{
    int pin;
    ServoTimer2* servo;

public:
    ServoRotate(int pin);
    void rotate();
};

ServoRotate::ServoRotate(int pin){
    this->pin = pin;
}

void ServoRotate::rotate(){
    int val = this->servo->read();
    this->servo->write(val+5);
    int val2 = this->servo->read();
}


#endif