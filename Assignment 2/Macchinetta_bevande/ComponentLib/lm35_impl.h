#ifndef __LM35__
#define __LM35__

#include "lm35.h"
#include <arduino.h>

class LM35Impl: public LM35 {

public:
  LM35Impl(int pin);

  virtual void convertToC(double value);

private:
  int pin;
};

#endif
