#include "sonarImpl.h"
#include "Arduino.h"

SonarImpl::SonarImpl(int trigPin, int echoPin){
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->tUS = 0.0;
}

SonarImpl::signal(){

}

SonarImpl::getDistance(){
    
}