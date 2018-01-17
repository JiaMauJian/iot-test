#include "Arduino.h"
#include <Servo.h> // Tower Pro SG90

class Flasher
{
    int ledPin;
    unsigned long OnTime;
    unsigned long OffTime;

    int ledState;
    unsigned long previousMillis;

    public:
    Flasher (int pin, unsigned long on, unsigned long off)
    {
        ledPin = pin;
        pinMode(ledPin, OUTPUT);

        OnTime = on;
        OffTime = off;

        ledState = LOW;
        previousMillis = 0;
    }

    void Update()
    {
        unsigned long currentMillis = millis();

        if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
        {
            ledState = LOW;
            previousMillis = currentMillis;
            digitalWrite(ledPin, ledState);
        }
        else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
        {
            ledState = HIGH;
            previousMillis = currentMillis;
            digitalWrite(ledPin, ledState);
        }
    }    
};

class Sweeper
{
    Servo servo;
    int pos;
    int increment;
    unsigned long updateInterval;
    unsigned long previousMillis;

    public:
    Sweeper(int interval)
    {
        updateInterval = interval;
        increment = 1;
        previousMillis = 0;
    }

    void Attach(int pin)
    {
        servo.attach(pin);
    }

    void Detach()
    {
        servo.detach();
    }

    void Update()
    {
        unsigned long currentMillis = millis();;

        if (currentMillis - previousMillis > updateInterval)
        {
            previousMillis = currentMillis;

            pos += increment;

            servo.write(pos);

            Serial.println(pos);

            if ((pos >= 180) || (pos <= 0))
            {
                increment = -increment;
            }    
        }
    }
};

Flasher ledGreen(12, 500, 500);
Sweeper sweeper1(15);

void setup()
{
    Serial.begin(9600);
    sweeper1.Attach(9);
}

void loop()
{
    ledGreen.Update();
    sweeper1.Update();
}