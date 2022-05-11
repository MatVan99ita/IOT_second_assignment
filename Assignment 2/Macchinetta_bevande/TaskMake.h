#ifndef __TASK_MAKE__
#define __TASK_MAKE__

#include "Arduino.h"
#include "bevandaImpl.h"
#include "Task.h"
#include "TaskTest.h"
#include "MsgService.h"
#include "ServoTimer2.h"

#define BEVERAGE_QUANTITY_TEST 1

class TaskMake: public Task {
    
public: 
  TaskMake(int servoPin);
  void init(int period);
  void tick();

private:
  ServoTimer2* servo;
  int servoPin;
  enum{WELCOME, READY, WAIT, MAKE} state;
    /*BevandaImpl* Chocolate;
    BevandaImpl* Tea;
    BevandaImpl* Coffee;
    String status;
    int PrimoAvvio = 0;
    TaskTest* test;*/
};

TaskMake::TaskMake(int servoPin){
  this->servoPin = servoPin;
}

void TaskMake::init(int period){
  Task::init(period);
  this->servo = new ServoTimer2();
  this->servo->attach(this->servoPin);
}

void TaskMake::tick(){
  
  int val = this->servo->read();
  this->servo->write(val+5);
  int val2 = this->servo->read();
  /*for(int i = 0; i < 180; i++){
    this->servo->write(i);
  }
  for(int i = 180; i > 0; i--){
    this->servo->write(i);
   }*/
}

#endif
