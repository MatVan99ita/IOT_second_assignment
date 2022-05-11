/*
*/
#include "Task.h"
#include "TaskMake.h"
#include "TaskAssistance.h"
#include "TaskTest.h"
#include "Scheduler.h"
#include "sleepTimer.h"

Scheduler* scheduler;
int servoPin = 10;

void setup(){
  Serial.begin(9600);
  scheduler->init(100);

  Task* t0 = new TaskMake(servoPin);
  t0->init(4000);

  Task* t1 = new TaskAssistance("Refill");
  t1->init(50000);

  Task* t2 = new TaskTest();
  t2->init(180000);

  Task* t3 = new SleepTimer();
  t3->init(60000);
  
  scheduler->addTask(t0);
  scheduler->addTask(t1);
  scheduler->addTask(t2);
  scheduler->addTask(t3);
}

void loop(){
  if(Assistance){
  }
  scheduler->schedule();
}