#ifndef __SONAR__
#define __SONAR__

#include "sonar.h"
#include "Arduino.h"

class SonarImpl{
public:
    SonarImpl(int trigPin, int echoPin);
    double getDistance();
    float signal(long signal);

private:
    int trigPin;
    int echoPin;
    long tUS;
};

#endif
