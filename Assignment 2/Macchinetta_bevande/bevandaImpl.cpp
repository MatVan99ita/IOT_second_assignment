#include "bevandaImpl.h"

BevandaImpl::BevandaImpl(){
    this->chocolate = 100;
    this->tea = 100;
    this->coffee = 100;
}

void BevandaImpl::makeBeverage(int beverage){
    switch (beverage)
    {
    case 0:
        this->chocolate--;
        break;
    case 1:
        this->tea--;
        break;
    case 2:
        this->coffee--;
        break;
    default:
        break;
    }
}

int BevandaImpl::getBeverage(int beverage){
    switch (beverage)
    {
    case 0:
        return this->chocolate;
    case 1:
        return this->tea;
    case 2:
        return this->coffee;
    default:
        return -1;
    }
}

void BevandaImpl::refillBeverage(){
    this->chocolate = 100;
    this->tea = 100;
    this->coffee = 100;
}