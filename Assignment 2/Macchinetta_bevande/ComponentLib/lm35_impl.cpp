#include "lm35_impl.h"
#include "Arduino.h"

LM35Impl::LM35Impl(int pin){
  this->pin = pin;
} 

double LM35Impl::convertToC(double value){
  int value_in_mV = 4.8876 * value; 
  double value_in_C = value_in_mV * 0.1;
  return value_in_C;
}
