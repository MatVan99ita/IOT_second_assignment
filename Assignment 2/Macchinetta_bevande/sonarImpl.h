#ifndef __SONAR__
#define __SONAR__

#include "sonar.h"
#include <arduino.h>

class SonarImpl: public Sonar {
    const float vs = 331.45 + 0.62*20;
    
public:
    SonarImpl(int trigPin, int echoPin);
    double getDistance();
    float signal(long signal);

private:
    int trigPin;
    int echoPin;
    long tUS;
    Sonar* sonar;
};

#endif