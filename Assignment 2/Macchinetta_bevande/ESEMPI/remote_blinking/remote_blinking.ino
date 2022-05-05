#include "Led.h"
#include "MsgService.h"

#define LED_PIN 13

Light* led;
char data;

void setup(){
  Serial.begin(9600);
  led = new Led(LED_PIN);  
  MsgService.init();
}

void loop(){
  if (MsgService.isMsgAvailable()){
    Msg* msg = MsgService.receiveMsg();    
    if (msg->getContent() == "1"){
       led->switchOn();
       Serial.println("si");
       MsgService.sendMsg("LED ON");
     } else if (msg->getContent() == "0"){
       led->switchOff();
       Serial.println("no");
       MsgService.sendMsg("LED OFF");       
     } 
    /* NOT TO FORGET: msg deallocation */
    delete msg;
  }
};
