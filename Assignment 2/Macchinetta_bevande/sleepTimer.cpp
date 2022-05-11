#include "sleepTimer.h"
#include "sonarImpl.h"

SleepTimer::SleepTimer(){
    this->lightSensor = new LightSensorImpl(A2);
    this->sonar = new SonarImpl(7, 8);
    int time = 0;
    this->lightLevel = 0;
    this->lightIntensity = 0;
    this->movement = true;
    this->distance = 0.0;
    l2c = new lcd_l2c();
}

void SleepTimer::init(int period){
    Task::init(period);
}

void SleepTimer::tick(){
    while(movement){
      this->l2c->print("Waiting for someone to come...");
      this->lightLevel = this->lightSensor->getLightIntensity() < 0 ? 0 : 
                        this->lightSensor->getLightIntensity() > 255 ? 255 : 
                        this->lightSensor->getLightIntensity();
      this->lightIntensity = 255 - this->lightLevel;
      this->distance = this->sensor->getDistance();
      MsgService.sendMsg( String(this->chocolate->getBeverage() + "-" + this->tea->getBeverage() + "-" + this->coffee->getBeverage() + "-0-Sleep") );
      if(lightIntensity <= 100 && this->distance < 20){
        //Ombra/Buio e persona vicina
        this->movement = false;1
      }
    }

    //Torna in Ready nel TaskMake

    
}
