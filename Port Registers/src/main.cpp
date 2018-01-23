#include "Arduino.h"

// pin13 = PB5
void setup()
{
    DDRB |= (1 << 5); // set pin13 as output
}

void loop()
{
    PORTB |= (1 << 5); // set output 13 HIGH
    delay(1000);
    PORTB &= ~(1 << 5); // set output 13 LOW
    delay(1000);
}