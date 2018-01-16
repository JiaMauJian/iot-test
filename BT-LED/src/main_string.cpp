// https://www.youtube.com/watch?v=x3KAXjnP06o&list=PLAROrg3NQn7cyu01HpOv5BWo217XWBZu0&index=30
// upload程式時，須將板子上的TX|RX線先拔掉，不然第一次讀訊息的時候會有亂碼

#include "Arduino.h"

int ledRed = 11;
int ledGreen = 12;

String readSerial;

void check();

void setup()
{
    delay(500);
    Serial.begin(38400);
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
}

void loop()
{
    while (Serial.available())
    {
        readSerial = Serial.readString();
        Serial.println(readSerial);
        check();        
    }
}

void check()
{
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);    

    if (readSerial == "red")
    {
        digitalWrite(ledRed, HIGH);
        Serial.println("red on");
    }

    if (readSerial == "green")
    {
        digitalWrite(ledGreen, HIGH);
        Serial.println("green on");
    }
}