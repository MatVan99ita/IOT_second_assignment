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
    this->servo->ServoMotorImpl(servoPin);
    this->lm35->LM35Impl(lmPin);
}

#endif