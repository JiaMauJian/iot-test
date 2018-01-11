// https://learn.adafruit.com/multi-tasking-the-arduino-part-1/using-millis-for-timing

//Become a clock-watcher!
//One simple technique for implementing timing is to make a schedule and keep an eye on the clock.  

#include "Arduino.h"

const int ledPin = 12;
const int ledPin2 = 13;

int led1_State = LOW;
int led2_State = LOW;

unsigned long previousMillis = 0;
unsigned long interval = 500;

void setup()
{
    pinMode(ledPin, OUTPUT);    
    pinMode(ledPin2, OUTPUT);    
	Serial.begin(9600);
}

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis > interval)
    {
        Serial.println(currentMillis);

        if (led1_State == LOW)
            led1_State = HIGH;
        else
            led1_State = LOW;

        if (led2_State == LOW)
            led2_State = HIGH;
        else
            led2_State = LOW;

        if ((currentMillis / 400) % 2 == 0) // LED明滅頻率為0.4秒
            digitalWrite(ledPin, led1_State);
        if ((currentMillis / 200) % 2 == 0) // LED明滅頻率為0.2秒
            digitalWrite(ledPin2, led2_State);

        previousMillis = currentMillis;
    }    
}