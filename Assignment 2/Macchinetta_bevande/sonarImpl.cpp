#include "sonarImpl.h"
#include "Arduino.h"

SonarImpl::SonarImpl(int trigPin, int echoPin){
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->tUS = 0.0;
}

float SonarImpl::signal(long signal){
    this->tUS = signal;
}

double SonarImpl::getDistance(){
    double t = this->tUS / 1000.0 / 1000.0 / 2;
    double d = t*vs;
    return d;
}