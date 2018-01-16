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
    TCNT1 = 3036; // �C��OverFlow�ɡATCNT1�|���]��0�A�q0�}�l�N���O1���_1���F�A�ҥH�o�̤@�����]��3036

    /*
4
8
12
...
40
������O4ms? �]��1��i�H�ƨ�16,000,000�A���ƨ�65535�ݭn�X��?
fclock = 16MHz = 1s

16,000,000     1
---------- = ------
   65535       x

x ��= 4ms

�p����: �p�Gbaud rate=9600�A�C�L���ɭԷ|���@���L340���ǰ��D
�Nbaud rate�]��115200�Y�i (platformio.ini�]�n�P�ɳ]�w)

�p�G�Q�n�ƺC�@�I(x�C�@�I)�O? �i�H���prescaler�A�pprescaler = 256

16,000,000 / prescaler      1
----------------------- = ------
         65535              x

x ��= 1.04s

BUT, �p�G�̭n���T�@�I��1���_1���O?�Ӥ��O1.04s

16,000,000 / 256            1
----------------------- = ------
         x                  1

x = 62500 steps

�ҥH�ڭ̤��q0�ơA�i�H�q3036�ƨ�65536 (65536-62500=3036)�AoverflowĲ�o���_��n1��

��z�᤽���p�U (�`�Nftarget�OHz���A�p�G�n0.5���@���N�O2Hz)

TCNT1 = 65536 - fclock / (prescaler * ftarget) = 65536 - 16000000 / (256*1)

�ҥH�n�]��TCNT1 = 3036


    */
}

void loop()
{
}