#ifndef __SONAR__
#define __SONAR__

#include "Arduino.h"

class Sonar {

public:
  virtual void signal() = 0;
  virtual double getDistance() = 0;
};

#endif
