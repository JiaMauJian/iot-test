#include "ProTrinketKeyboard.h"
#include "Bounce.h"

const int CAPITAL_A_PIN = 12;
Bounce bouncer(CAPITAL_A_PIN, 50);
const int STRING_PIN = 11;

void setup() {
  pinMode(CAPITAL_A_PIN, INPUT_PULLUP);
  pinMode(STRING_PIN, INPUT_PULLUP);

  TrinketKeyboard.begin();
  Serial.begin(9600);
}

void loop() {
  TrinketKeyboard.poll();

/*
  if (bouncer.update() == true && bouncer.read() == LOW)
  {
    TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_SHIFT, KEYCODE_A);
    TrinketKeyboard.pressKey(0, 0);
  }
*/

  bool updateState = bouncer.update();
  if (bouncer.read() == LOW)
  {
    Serial.println(bouncer.duration());
    
    if (bouncer.duration() >= 200 && bouncer.duration() < 2000) //按著不放連續2秒
    {      
      TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_SHIFT, KEYCODE_A);
      TrinketKeyboard.pressKey(0, 0);
    }
    
    if (updateState)
    {
      TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_SHIFT, KEYCODE_A);
      TrinketKeyboard.pressKey(0, 0);
    }
  }
  
  if (digitalRead(STRING_PIN) == LOW)
  {
    TrinketKeyboard.print("Hello World!");
  }
}
