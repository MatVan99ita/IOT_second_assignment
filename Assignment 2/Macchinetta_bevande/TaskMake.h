#ifndef __TASK_MAKE__
#define __TASK_MAKE__

#include "Arduino.h"
#include "bevandaImpl.h"
#include "Task.h"
#include "TaskTest.h"
#include "MsgService.h"
#include "ServoRotate.h"
#include "lcd_l2c.h"
#include "MsgService.h"

class TaskMake: public Task {
    
public: 
  TaskMake(int servoPin);
  void init(int period);
  void tick();

private:
  ServoRotate* servo;
  int servoPin;
  BevandaImpl* Chocolate;
  BevandaImpl* Tea;
  BevandaImpl* Coffee;
  bool Assistance;
  lcd_l2c* l2c;
  enum{WELCOME, READY, WAIT, MAKE, ASSISTANCE} state;
  enum{CHOCOLATE, TEA, COFFEE, nope} beverages;
};

TaskMake::TaskMake(int servoPin){
  this->servoPin = servoPin;
  this->servo = new ServoRotate(this->servoPin);
  this->state = WELCOME;
  this->Chocolate = new BevandaImpl();
  this->Tea = new BevandaImpl();
  this->Coffee = new BevandaImpl();
  this->l2c = new lcd_l2c();
  this->beverages = CHOCOLATE;
  this->Assistance = false;
}

void TaskMake::init(int period){
  Task::init(period);
  MsgService.init();
  this->state = this->state == WELCOME ? READY: WAIT;
}

void TaskMake::tick(){
  switch (state)
  {
    case MAKE:
      this->l2c->print("Choose beverage");
      this->servo->rotate();
      switch (beverages)
      {
        case CHOCOLATE:
          if(this->Chocolate->getBeverage() >= 0){
            this->Chocolate->makeBeverage();                                                                                                 //0 = self test eseguiti
            MsgService.sendMsg( String(this->chocolate->getBeverage() + "-" + this->tea->getBeverage() + "-" + this->coffee->getBeverage() + "-0-Making") );
          } else {
            this->state = ASSISTANCE;
          }
          break;
        case TEA:
          if(this->Tea->getBeverage() >= 0){
            this->Tea->makeBeverage();
            MsgService.sendMsg( String(this->chocolate->getBeverage() + "-" + this->tea->getBeverage() + "-" + this->coffee->getBeverage() + "-0-Making") );
          } else {
            this->state = ASSISTANCE;
          }
          break;
        case COFFEE:
          if(this->Coffee->getBeverage() >= 0){
            this->Coffee->makeBeverage();
            MsgService.sendMsg( String(this->chocolate->getBeverage() + "-" + this->tea->getBeverage() + "-" + this->coffee->getBeverage() + "-0-Making") );
          } else {
            this->state = ASSISTANCE;
          }
          break;
        default:
          break;
      }
      break;

    case WAIT:
      l2c->print("Scegli una bevanda...");
      //Selezione bevanda e passaggio a make
      MsgService.sendMsg( String(this->chocolate->getBeverage() + "-" + this->tea->getBeverage() + "-" + this->coffee->getBeverage() + "-0-Wait") );
      this->state = MAKE;
      break;

    case WELCOME:
      l2c->print("Welcome...");
      state = READY;
      break;

    case READY:
      l2c->print("Ready...");
      MsgService.sendMsg( String(this->chocolate->getBeverage() + "-" + this->tea->getBeverage() + "-" + this->coffee->getBeverage() + "-0-Ready") );
      state = WAIT;
      break;

    case ASSISTANCE:
      l2c->print("Assistance needed...");
      this->Assistance = true;
      break;
    
    default:
      state = READY;
      break;
  }
}

extern bool Assistance;
#endif
