#ifndef __LM35_IMPL__
#define __LM35_IMPL__

#include "lm35.h"
#include <arduino.h>

class LM35Impl: public LM35 {

public:
  LM35Impl(int pin);
  double convertToC(double value);

private:
  int pin;
};

#endif
