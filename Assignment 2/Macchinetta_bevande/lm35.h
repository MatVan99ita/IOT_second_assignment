#ifndef __LM35__
#define __LM35__

class LM35 {

public:
  virtual void convertToC(double value) = 0;
  virtual bool checkTemp() = 0;
};

#endif