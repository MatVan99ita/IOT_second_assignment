#ifndef __BEVANDA__
#define __BEVANDA__

class Bevanda {

    public:
        virtual void makeBeverage(int beverage) = 0;
        virtual int getBeverage(int beverage) = 0;
        virtual void refillBeverage() = 0;
};

#endif