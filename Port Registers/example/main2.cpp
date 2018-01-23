#include "Arduino.h"

// pin13 = PB5

#define bitMask _BV(5)

void setup()
{
    DDRB |= bitMask; // set pin13 as output
}

void loop()
{
    PORTB |= bitMask; // set output 13 HIGH
    delay(1000);
    PORTB &= ~bitMask; // set output 13 LOW
    delay(1000);
}