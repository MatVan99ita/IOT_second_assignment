#ifndef __TASKTEST__
#define __TASKTEST__


#include "Arduino.h"
#include "ServoTimer2.h"
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

    void makeTest()

private:
    int self_test;
    ServoTimer2* servo;
    LM35* lm35;
};

void TaskTest::makeTest(){
}

#endif