#ifndef __LM35_IMPL__
#define __LM35_IMPL__

#include "lm35.h"
#include <arduino.h>

class LM35Impl: public LM35 {

public:
  LM35Impl(int pin);
  void convertToC(double value);
  bool checkTemp();

private:
  int pin;
  double valueInC;
};

#endif
