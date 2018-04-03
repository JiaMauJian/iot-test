#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_5 = CapacitiveSensor(4, 5);

void setup() {    
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  long start = millis();
  long total = cs_4_5.capacitiveSensor(30);

  Serial.print(millis() - start);
  Serial.print("\t");

  Serial.println(total);

  if (total > 50)
    digitalWrite(13, HIGH);

  if (total == 0)
    digitalWrite(13, LOW);
    
  delay(10);
}
