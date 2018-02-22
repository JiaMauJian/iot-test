#include "Arduino.h"
#include "LiquidCrystal.h" //platformio lib install 887

// LCD1624腳位 (非I2C要接很多線)
/*
1 Vcc   -> V5
2 GND   -> GND
3 Vo    -> GND 或是接可變電阻可調整亮度 (Vo與Vcc差距越大會越亮)
4 RS    -> pin8
5 RW    -> GND
6 En    -> pin9
11 DB4  -> pin10
12 DB5  -> pin11
13 DB6  -> pin12
14 DB7  -> pin13
*/

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    lcd.begin(16, 2);
    lcd.print("hello, world!");
}

void loop()
{
    lcd.setCursor(0, 1);
    lcd.print(millis() / 1000);
} 