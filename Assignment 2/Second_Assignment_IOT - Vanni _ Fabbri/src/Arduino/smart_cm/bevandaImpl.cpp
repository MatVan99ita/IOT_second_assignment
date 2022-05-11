#include "bevandaImpl.h"

BevandaImpl::BevandaImpl(){
    this->beverage = BEVERAGE_QUANTITY_TEST;
}

void BevandaImpl::makeBeverage(){
    this->beverage--;
}

int BevandaImpl::getBeverage(){
    return this->beverage;
}

void BevandaImpl::setQuantity(int quantity){
    this->beverage = quantity;
}

void BevandaImpl::refillBeverage(){
    this->beverage = 100;
}