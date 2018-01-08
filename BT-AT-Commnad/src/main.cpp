// http://jackedu.blogspot.tw/2015/01/hc-05.html

// Arduino通電後，連接5V的pin腳接上Arduino（此時藍芽模組上的led燈會慢速閃爍(約兩秒一次)，表示藍芽模組已進入AT模式

// 藍芽模組燈號快閃 -> 找配對
// 藍芽模組燈號慢閃 -> AT模式

// 用Termite或其他工具測試AT Command

#include "Arduino.h"
#include <SoftwareSerial.h>
#define KEY_PIN 9

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  pinMode(KEY_PIN, OUTPUT);
  digitalWrite(KEY_PIN, HIGH);

  Serial.begin(9600);
  Serial.println("Enter AT Command:");
  BTSerial.begin(38400); // HC-05 default baud-rate
}

void loop()
{ 
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  
  if (Serial.available())
    BTSerial.write(Serial.read());
}