#ifndef __BEVANDA_IMPL__
#define __BEVANDA_IMPL__

#include "bevanda.h"

class BevandaImpl: public Bevanda {

public:
  BevandaImpl();
  void makeBeverage(int beverage);
  int getBeverage(int beverage);
  void refillBeverage();

private:
  int beverage;
};

#endif