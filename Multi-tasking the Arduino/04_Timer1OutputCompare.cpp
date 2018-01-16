// https://www.youtube.com/watch?v=IdL0_ZJ7V2s
#include "Arduino.h"

void setup()
{
    Serial.begin(115200);
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B |= (1 << CS12) | (1 << WGM12); // prescaler 256, CTC Mode

    /*
              fclock
     ---------------------- - 1
      (prescaler * ftarget)   

      (注意ftarget是Hz單位，如果要0.5秒做一次就是2Hz)
    */


    OCR1A = (16000000 / (256*2)) - 1; // ftarget = 2 Hz
    OCR1B = (16000000 / (256*4)) - 1; // ftarget = 4 Hz

    TIMSK1 |= (1 << OCIE1A) | (1 << OCIE1B); // enable OCR1A/OCR1B interrupt
}

ISR(TIMER1_COMPA_vect)
{
    Serial.println(millis());
}

ISR(TIMER1_COMPB_vect)
{
    Serial.println(millis());
}

void loop()
{
}