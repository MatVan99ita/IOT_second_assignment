#include "lm35_impl.h"
#include "Arduino.h"

LM35Impl::LM35Impl(int pin){
  this->pin = pin;
} 

void LM35Impl::convertToC(double value){
  int value_in_mV = 4.8876 * value; 
  double value_in_C = (value_in_mV - 500) * 0.1;
  this->valueInC = value_in_C;
  //return value_in_C;
}

bool LM35Impl::checkTemp(){
  return this->valueInC >= 17 && this->valueInC <= 27;
}
