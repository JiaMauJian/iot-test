// 這是另一種狀態改變的手法，FlashWithoutDelay，可依照狀態時間長短改變，如亮個250ms，暗個750ms
// 不過我覺得這個方式用在多種狀態下，更能凸顯該方法，如狀態1要500ms, 狀態2要1000ms, 狀態3要300ms...

// 這個寫法跟BlinkWithoutDelay有什麼不同? Flash和Blink有什麼不同?
// Blink就是固定時間長度改變狀態，如interval=500ms，就是亮個500ms，暗個500ms
// Flash就是不固定時間長度改變狀態，如OnTime = 250ms, OffTime = 750ms

// 講了這麼多，以上就是在講State Machine的觀念

/* State + Machine = State Machine
   Note that we have variables to keep track of whether the LED is ON or OFF.
   And variables to keep track of when the last change happened.   
   That is the "State" part of the State Machine.  

   We also have code that looks at the state and decides when and how it needs to change.  
   That is the "Machine" part.  
   Every time through the loop we ‘run the machine’ and the machine takes care of updating the state.
*/

#include "Arduino.h"

const int ledPin = 12;
const int ledPin2 = 13;

int led1_State = LOW;
int led2_State = LOW;

unsigned long previousMillis = 0;
unsigned long OnTime = 250;
unsigned long OffTime = 750;

void setup()
{
    pinMode(ledPin, OUTPUT);    
}

void loop()
{
    unsigned long currentMillis = millis();
    
    if ((led1_State == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
        led1_State = LOW;
        previousMillis = currentMillis;
        digitalWrite(ledPin, led1_State);
    }
    else if ((led1_State == LOW) && (currentMillis - previousMillis >= OffTime))
    {
        led1_State = HIGH;
        previousMillis = currentMillis;
        digitalWrite(ledPin, led1_State);
    }
}