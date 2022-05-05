#ifndef __LM35__
#define __LM35__

class LM35 {

public:
  virtual double convert(double value) = 0;
};

#endif