#include "Arduino.h"
#include "U8glib.h"

// pio lib install "U8glib"

U8GLIB_ST7920_128X64_1X u8g(12, 11, 10);	// Enable, RW , RS
void draw();
void ST9720_Display();

void setup()
{        
    Serial.begin(9600);
    u8g.setFont(u8g_font_8x13);
    u8g.setColorIndex(1); // pixel on
}

void draw() {  
  u8g.setFont(u8g_font_courB10); // https://github.com/olikraus/u8glib/wiki/fontgroupadobex11
  u8g.drawStr(0, 18, "hello, world!"); //
  byte val = map(analogRead(A0), 0, 1023, 0, 127);
  u8g.drawBox(0, 28, val, 10);
}

void ST9720_Display()
{
    u8g.firstPage();
    do {     
        draw();
    } while( u8g.nextPage() );    
}

void loop()
{
    ST9720_Display();
}