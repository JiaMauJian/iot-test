#include "Arduino.h"
#define LED_PIN 13

int state = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(38400); // HC-05，HC-05 TX|RX與Arduino RX|TX串接
}

void loop()
{  
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (Serial.available() > 0)
  {
    state = Serial.read();

    if (state == '1')
    { 
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED : ON");
      state = 0;
    }
    else if (state == '0')
    {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED : OFF");
      state = 0;
    }
  }  
}