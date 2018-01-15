# PlatformIO Quick Start
* http://docs.platformio.org/en/latest/quickstart.html
* 原來不一定要用Arduino IDE也可以將程式寫入Arduino (main.cpp不一定要.ino)

# BlueTooth (HC-05)
* 一開始如果都搞不定也連不到就直接進AT下Command重設為原廠設定 (AT+ORGL) [AT Command](http://www.linotux.ch/arduino/HC-0305_serial_module_AT_commamd_set_201104_revised.pdf)
* 用App(Arduino BlueTooth)測試LED

# LED + 電阻 (限流 降壓)
* 不要小看這小小的範例，有些觀念很重要，如歐姆定律還有為什麼一定要加電阻 [Electronic Basics #8](https://www.youtube.com/watch?v=Qlayua3yjuE)
* 或像是要用[電阻來降藍芽模組RX腳位的電壓](https://swf.com.tw/?p=705) (我測試藍芽時，沒將Arduino 5V降壓而是直接使用3.3V腳位)

# Multi-tasking the Arduino
* [一張圖表達Multi-tasking](https://s3.amazonaws.com/learn-production/guides/images/000/000/799/medium800/368px-One_man_band__CDV_by_Knox__c1865.JPG?1448301986)

* 多工的進化過程: delay() -> clock-watcher -> interrupt
  - 除非真的有很即時性的需求，在用中斷，不然我覺得clock-watcher的程式模式已經很棒了

* 02_FlashWithoutDelay.cpp，這是另一種狀態改變的手法，可依照狀態時間長短改變，如亮個250ms，暗個750ms

不過我覺得這個方式用在多種狀態下，更能凸顯該方法，如狀態1要500ms, 狀態2要1000ms, 狀態3要300ms...

這個寫法跟BlinkWithoutDelay有什麼不同? Flash和Blink有什麼不同?

Blink就是固定時間長度改變狀態，如interval=500ms，就是亮個500ms，暗個500ms

Flash就是不固定時間長度改變狀態，如OnTime = 250ms, OffTime = 750ms

講了這麼多，以上就是在講State Machine的觀念

  State + Machine = State Machine

   Note that we have variables to keep track of whether the LED is ON or OFF.
   And variables to keep track of when the last change happened.   
   That is the "State" part of the State Machine.  

   We also have code that looks at the state and decides when and how it needs to change.  
   That is the "Machine" part.  
   Every time through the loop we ‘run the machine’ and the machine takes care of updating the state.
  
# Interrupt?
  - An interrupt is a signal that tells the processor to immediately stop what it is doing and handle some high priority processing.  

* TIMSK0.pptx

* 使用Timer方式來執行中斷
  - [Going beyond Arduino](https://www.youtube.com/watch?v=n0MNraPWQYo)
  - [Electronic Basics #30 Timer](https://www.youtube.com/watch?v=IdL0_ZJ7V2s) 這個講得很清楚

* 怎麼看Datasheet
 - [ATmega328 block diagram TC0/TC1/TC2](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf#page=13)
 - [TC1 - 16-bit Timer/Counter1 with PWM](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf#page=149) TC1 Timer有PWM功能，我們先試試最簡單的Normal Mode
 - [Normal Mode](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf#page=161) Normal Mode設定TCCR1A.WGM1[3:0]=0x0，是0數到65535，超過時便會觸發Overflow中斷
 - TCCR1A.WGM1[3:0]=0x0意思是TCCR1A.WGM10, 11, 12, 13都設為0 [Waveform Generation Mode Bit Description] (http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf#page=171)
 - WGM10, 11在[TCCR1A](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf#page=170)
 - WGM12, 13在[TCCR1B](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf#page=173)
 - prescaler選用[Clock Select Bit Description](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf#page=173)
 - 把timer overflow功能打開 [TOIE](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf#page=184)
 
* Interrupt (OverFlow)
 - 04_Timer1OverFlow(程式有詳解)
 
* Interrupt (Output Compare)
 - 04_Timer1OutputCompare(程式有詳解)
  
# 認識與實驗Arduino的睡眠模式
  - [Arduino的睡眠模式](https://swf.com.tw/?p=525)
  - [量電流](http://www.electrodragon.com/measure-a-system-current-consumption-draw-arduino-in-case/)
