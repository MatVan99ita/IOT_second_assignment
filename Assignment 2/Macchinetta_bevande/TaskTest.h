#ifndef __TASKTEST__
#define __TASKTEST__


#include "Arduino.h"
#include "servo_motor_impl.h"
#include "lm35_impl.h"

class TaskTest
{
public:
    TaskTest(){
        this->self_test = 0;
    }

    void setSelfTest(int test){
        this->self_test = test;
    }

    int getSelfTest(){
        return this->self_test;
    }

    void makeTest(int servoPin, int lmPin);

private:
    int self_test;
    ServoMotorImpl* servo;
    LM35* lm35;
};

void TaskTest::makeTest(int servoPin, int lmPin){
    this->servo->on(int servoPin);
    for(int i = 0; i < 180; i++){
        this->servo->setPosition(i);
    }
    for(int i = 180; i > 0; i--){
        this->servo->setPosition(i);
    }
    this->servo->off();

    this->lm35->LM35Impl(lmPin);


}

#endif