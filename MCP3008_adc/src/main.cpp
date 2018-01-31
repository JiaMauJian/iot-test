#include "Arduino.h"
#include "MCP3008.h"

#define CS_PIN 9
#define MOSI_PIN 10
#define MISO_PIN 11
#define CLOCK_PIN 12

MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);

void setup()
{
    Serial.begin(9600);    
}

void loop()
{
    int val = adc.readADC(0);
    Serial.println(val);
    delay(500);
}