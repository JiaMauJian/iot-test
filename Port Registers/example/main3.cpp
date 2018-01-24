#include "Arduino.h"

void setup()
{    
    Serial.begin(9600);
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);    
}

void loop()
{
    byte inputs = 0;
    if (digitalRead(2)) inputs +=1;
    if (digitalRead(3)) inputs +=2;
    if (digitalRead(4)) inputs +=4;
    if (digitalRead(5)) inputs +=8;
    if (digitalRead(6)) inputs +=16;
    if (digitalRead(7)) inputs +=32;
    if (digitalRead(8)) inputs +=64;
    if (digitalRead(9)) inputs +=128;
    Serial.write(inputs);
    delay(1000);
}