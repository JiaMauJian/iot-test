#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"


Adafruit_7segment matrix = Adafruit_7segment();

void setup()
{
    matrix.begin(0x70);
}

void loop()
{
  matrix.print(10000, DEC);
  matrix.writeDisplay();
  delay(500);

  matrix.print(0xBEFF, HEX);
  matrix.writeDisplay();
  delay(500);

  matrix.print(12.34);
  matrix.writeDisplay();
  delay(500);

  for (uint16_t counter = 0; counter < 9999; counter++)
  {
    matrix.print(counter);
    matrix.writeDisplay();
    delay(10);
  }
}
