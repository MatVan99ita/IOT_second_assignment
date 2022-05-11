#ifndef __BEVANDA_IMPL__
#define __BEVANDA_IMPL__

#include "bevanda.h"
#define BEVERAGE_QUANTITY_TEST 1 //usata per testare anche la modalità Refill in poco tempo

class BevandaImpl: public Bevanda {

public:
  BevandaImpl();
  void makeBeverage();
  int getBeverage();
  void setQuantity(int quantity);
  void refillBeverage();

private:
  int beverage;
};

#endif