#ifndef __TASK_MAKE__
#define __TASK_MAKE__

#include "Arduino.h"
#include "bevandaImpl.h"
#include "TaskTest.h"

#define BEVERAGE_QUANTITY_TEST 3

class Task_Make {
    
public: 

  void init(){
    this->status = "Welcome";
    this->Chocolate = new BevandaImpl(BEVERAGE_QUANTITY_TEST);
    this->Tea->setQuantity(BEVERAGE_QUANTITY_TEST);
    this->Coffee->setQuantity(BEVERAGE_QUANTITY_TEST);
  }  

  bool isMsgAvailable();
  Msg* receiveMsg();

  bool isMsgAvailable(Pattern& pattern);
  Msg* receiveMsg(Pattern& pattern);
  
  void sendMsg(const Msg& msg);
  void sendMsg(const String& msg);

private:
  BevandaImpl Chocolate;
  BevandaImpl Tea;
  BevandaImpl Coffee;
  String status;
  int PrimoAvvio = 0;

};

extern MsgServiceClass MsgService;

#endif
