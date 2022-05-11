#ifndef __BEVANDA__
#define __BEVANDA__

class Bevanda {

    public:
        virtual void makeBeverage() = 0;
        virtual int getBeverage() = 0;
        virtual void refillBeverage() = 0;
};

#endif