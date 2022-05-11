#ifndef __LCD_L2C__
#define __LCD_L2C__

#include <LiquidCrystal_I2C.h>
#include "Arduino.h"
class lcd_l2c
{
private:
    LiquidCrystal_I2C* lcd;
public:
    lcd_l2c();
    void print(String msg);
};

lcd_l2c::lcd_l2c()
{
  lcd = new LiquidCrystal_I2C(0x27,20,4);
  this->lcd->init();
  this->lcd->backlight();
}

void lcd_l2c::print(String msg)
{
    this->lcd->clear();
    this->lcd->setCursor(2, 1);
    this->lcd->println(msg);
}


#endif