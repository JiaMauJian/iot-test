# 為什麼要燒錄ATMEGA328P-PU?
在測試馬達的時候(HP Server上拔下來的)，好像把uno的板子搞壞，因在upload程式的出現底下錯誤訊息
```
avrdude: verification error, first mismatch at byte 0x0000
         0xff != 0x0c
avrdude: verification error; content mismatch
```
查了一下，好像只要把ATMEGA328P-PU的晶片換掉就好，但我用uno當ISP燒錄器有奇奇怪怪問題，板子壞得很徹底，還好手邊還有一塊之前專案留下的Mega 2560的板子可以拿來當ISP

1. [參考網址](https://www.youtube.com/watch?v=cebMSJrNntI&t=12s) 不使用16 MHz crystal石英晶體燒錄程式，使用Arduino IDE 1.6.7搭配[breadboard-1-6-x.zip](https://www.arduino.cc/en/Tutorial/ArduinoToBreadboard)
2. 把上面使用uno的部分換成mega，需注意腳位
```
Mega2560 -> atmega328p-pu

MOSI 51 -> MOSI17
MISO 50 -> MISO 18
SCK 52 -> SCK 19
RESET 10 -> RESET 1
```
3. [參考網址](http://yehnan.blogspot.tw/2013/02/arduino-unoispbootloadersketchatmega328.html)一般的sketch燒錄到麵包板上的ATmega328P-PU晶片裡，有兩種做法，一是像老外的影片中示範將uno上的ATmega328P-PU晶片拔掉(bootloader與sketch共存，就跟平常使用Arduino板子時一樣)，二是直接使用保留燒錄bootloader的線路，board=ATmega328 on breadboard，Programmer=Arduino as ISP，用Sketch->Upload Using Programmer，如把Blink程式燒進去(燒錄sketch會蓋掉先前的bootloader)

# 燒錄遇到的問題
* 這個訊息不用理會
```
Board breadboard:avr:atmega328bb doesn't define a 'build.board' preference. Auto-set to: AVR_ATMEGA328BB
```
* 晶片壞了
```
avrdude: Device signature = 0x000000
```
* 線路可能接錯或是晶片壞了
```
avrdude: Yikes!  Invalid device signature.
         Double check connections and try again, or use -F to override
         this check.
```
* device signature是什麼
```
Atmel的微控制器晶片都有個識別碼（device signature），譬如ATmega328是0x1E 0x95 0x14，ATmega328P是0x1E 0x95 0x0F。

錯誤訊息告訴我們，avrdude收到指令想要燒錄某顆晶片，可是電路裡的實際晶片卻是另外一顆，不符合，所以停止燒錄。

http://yehnan.blogspot.tw/2013/02/arduino-unoispbootloadersketchatmega328.html
```
