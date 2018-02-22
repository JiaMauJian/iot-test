#include "Arduino.h"
#include <OneWire.h> // pio lib install "OneWire"
#include <DallasTemperature.h> // pio lib install "DallasTemperature"



OneWire oneWire(10);
DallasTemperature ds(&oneWire);

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);

    Serial.begin(9600);
    ds.begin();
}

void loop()
{
    ds.requestTemperatures();
    Serial.println(ds.getTempCByIndex(0));

    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    delay(500);
}