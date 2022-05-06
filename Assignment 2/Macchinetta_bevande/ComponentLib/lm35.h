#ifndef __LM35__
#define __LM35__

class LM35 {

public:
  virtual double convertToC(double value) = 0;
};

#endif