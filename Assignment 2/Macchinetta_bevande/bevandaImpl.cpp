#include "bevandaImpl.h"

BevandaImpl::BevandaImpl(){
    this->beverage = 100;
}

void BevandaImpl::makeBeverage(int beverage){
    this->beverage--;
}

int BevandaImpl::getBeverage(int beverage){
    return this->beverage;
}

void BevandaImpl::refillBeverage(){
    this->beverage = 100;
}