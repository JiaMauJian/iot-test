#include "Arduino.h"

class Flasher
{
    int _ledPin;
    unsigned long _OnTime;
    unsigned long _OffTime;

    int _ledState;
    unsigned long _previousMillis;

    public:
    Flasher(int ledPin,  unsigned long OnTime, unsigned long OffTime)
    {
        _ledPin = ledPin;
        pinMode(_ledPin, OUTPUT);

        _OnTime = OnTime;
        _OffTime = OffTime;

        _ledState = LOW;
        _previousMillis = 0;
    }

    void Update()
    {
        unsigned long currentMillis = millis();
        
        if ((_ledState == HIGH) && (currentMillis - _previousMillis >= _OnTime))
        {
            _ledState = LOW;
            _previousMillis = currentMillis;
            digitalWrite(_ledPin, _ledState);
        }
        else if ((_ledState == LOW) && (currentMillis - _previousMillis >= _OffTime))
        {
            _ledState = HIGH;
            _previousMillis = currentMillis;
            digitalWrite(_ledPin, _ledState);
        }
    }
};

Flasher led1(12, 100, 400);
Flasher led2(13, 350, 350);
Flasher led3(11, 100, 100);

void setup()
{    
}

void loop()
{
    led1.Update();
    led2.Update();
    led3.Update();
}