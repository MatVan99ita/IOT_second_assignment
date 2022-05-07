#ifndef __SONAR__
#define __SONAR__

#include "sonar.h"
#include <arduino.h>

class SonarImpl: public Sonar {

public:
    SonarImpl(int trigPin, int echoPin);
    double getDistance();
    float signal();

private:
    int trigPin;
    int echoPin;
    long tUS;
    Sonar* sonar;
};

#endif