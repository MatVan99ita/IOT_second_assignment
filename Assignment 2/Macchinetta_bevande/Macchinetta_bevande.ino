/*
*/
#include "Task.h"
#include "bevandaImpl.h"
#include "TaskMake.h"
#include "TaskAssistance.h"
//#include "ServoRotate.h"
#include "TaskTest.h"
#include "Scheduler.h"

Scheduler* scheduler;
int servoPin = 10;

void setup(){
  Serial.begin(9600);
  scheduler->init(100);

  Task* t0 = new TaskMake(servoPin);
  t0 -> init(100);

  scheduler->addTask(t0);

}

void loop(){
  scheduler->schedule();
}