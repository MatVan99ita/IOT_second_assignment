#ifndef __TASKTEST__
#define __TASKTEST__


#include "Arduino.h"
#include "ServoRotate.h"
#include "lm35_impl.h"
#include "lcd_l2c.h"
#include "Task.h"

class TaskTest: public Task
{
public:
    TaskTest();
    //void makeTest(int servoPin, int lmPin);
    void init(int period);
    void tick();

private:
    int self_test;
    ServoRotate* servo;
    //LM35* lm35;
    lcd_l2c* l2c;
};

TaskTest::TaskTest(){
  this->self_test = 0;
  this->l2c = new lcd_l2c();
  this->servo = new ServoRotate(10);
}

void TaskTest::init(int period){
  Task::init(period);
}

void TaskTest::tick(){
  this->l2c->print("ASSISTEMIAMO");
  this->servo->rotate();
}

#endif