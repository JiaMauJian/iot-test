#include "Arduino.h"
#include "U8glib.h"

// pio lib install "U8glib"

U8GLIB_ST7920_128X64_1X u8g(12, 11, 10);	// Enable, RW , RS
void draw();
void ST9720_Display();

//char adcResult[4]; // 8-bit (0 0 0 '\0')
char adcResult[5]; // 10-bit (0 0 0 0 '\0')
uint16_t tenBitValue;

void setup()
{        
    ADCSRA = 0;
    ADMUX = 0;

    ADCSRA |= (1 << ADEN); // Enable ADC
    ADCSRA |= (1 << ADIE); // Enable ADC Interrupt

    // By default, the successive approximation circuitry requires an input clock frequency between 50kHz and 200kHz to get maximum resolution.
    // The Arduino Uno has a system clock of 16Mhz
    // 16,000,000 / 50,000 = 320
    // 16,000,000 / 200,000 = 80
    // Select prescaler between 80 and 320, prescaelr is 128
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

    ADMUX |= (1 << ADLAR); // ADC Left Adjust Result    
    ADMUX |= (1 << MUX0); // pin = A1
    ADMUX |= (1 << REFS0); // AVCC with external capacitor at AREF pin

    ADCSRA |= (1 << ADSC); // Start Conversion

    Serial.begin(9600);
    u8g.setFont(u8g_font_8x13);
    u8g.setColorIndex(1); // pixel on
}

void draw() {  
  u8g.setFont(u8g_font_courB18); // https://github.com/olikraus/u8glib/wiki/fontsize
  u8g.drawStr(0, 18, adcResult); //
  byte val = map(tenBitValue, 0, 1023, 0, 127);
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

ISR(ADC_vect)
{
    uint8_t theLow = ADCL;
    tenBitValue = ADCH << 2 |  theLow >> 6;
    itoa(tenBitValue, adcResult, 10);
    //Serial.println(tenBitValue);
    // 為什麼可變電阻調到最大時，LCD只有顯示到1021~1022
    // 因為LCD吃了一些電(不到參考電壓)，把LCD的電拔掉，用Serial Print出來就會有1023
    ADCSRA |= (1 << ADSC);
}