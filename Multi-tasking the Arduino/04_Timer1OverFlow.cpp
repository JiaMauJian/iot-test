// https://www.youtube.com/watch?v=IdL0_ZJ7V2s
#include "Arduino.h"

int ledPin = 13;

void setup()
{
    Serial.begin(115200);
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 3036;
    //TCCR1B |= (1 << CS10); // prescaler 1
    TCCR1B |= (1 << CS12); // prescaler 256
    TIMSK1 |= (1 << TOIE1); // enable overflow interrupt
}

ISR(TIMER1_OVF_vect)
{
    digitalWrite(ledPin, !digitalRead(ledPin));
    Serial.println(millis());
    TCNT1 = 3036; // 每次OverFlow時，TCNT1會重設為0，從0開始就不是1秒中斷1次了，所以這裡一直重設為3036

    /*
4
8
12
...
40
為什麼是4ms? 因為1秒可以數到16,000,000，那數到65535需要幾秒?
fclock = 16MHz = 1s

16,000,000     1
---------- = ------
   65535       x

x 約= 4ms

小插曲: 如果baud rate=9600，列印的時候會有一直印340的怪問題
將baud rate設成115200即可 (platformio.ini也要同時設定)

如果想要數慢一點(x慢一點)呢? 可以選用prescaler，如prescaler = 256

16,000,000 / prescaler      1
----------------------- = ------
         65535              x

x 約= 1.04s

BUT, 如果們要更精確一點到1秒中斷1次呢?而不是1.04s

16,000,000 / 256            1
----------------------- = ------
         x                  1

x = 62500 steps

所以我們不從0數，可以從3036數到65536 (65536-62500=3036)，overflow觸發中斷剛好1秒

整理後公式如下 (注意ftarget是Hz單位，如果要0.5秒做一次就是2Hz)

TCNT1 = 65536 - fclock / (prescaler * ftarget) = 65536 - 16000000 / (256*1)

所以要設成TCNT1 = 3036


    */
}

void loop()
{
}