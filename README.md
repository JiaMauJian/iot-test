# PlatformIO Quick Start
* http://docs.platformio.org/en/latest/quickstart.html
* 原來不一定要用Arduino IDE也可以將程式寫入Arduino (main.cpp不一定要.ino)

# BlueTooth (HC-05)
* 一開始如果都搞不定也連不到就直接進AT下Command重設為原廠設定 (AT+ORGL) [AT Command](http://www.linotux.ch/arduino/HC-0305_serial_module_AT_commamd_set_201104_revised.pdf)
* 用App(Arduino BlueTooth)測試LED

# LED + 電阻 (限流 降壓)
* 不要小看這小小的範例，有些觀念很重要，如歐姆定律還有為什麼一定要加電阻 [Electronic Basics #8](https://www.youtube.com/watch?v=Qlayua3yjuE)
* 或像是要用[電阻來降藍芽模組RX腳位的電壓](https://swf.com.tw/?p=705) (我測試藍芽時，沒將Arduino 5V降壓而是直接使用3.3V腳位)

# Multi-tasking the Arduino [傳神](https://s3.amazonaws.com/learn-production/guides/images/000/000/799/medium800/368px-One_man_band__CDV_by_Knox__c1865.JPG?1448301986)
* 多工的進化過程: delay() -> clock-watcher -> interrupt

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
  
* What is an Interrupt?
  - An interrupt is a signal that tells the processor to immediately stop what it is doing and handle some high priority processing.  
  
* TIMSK0.pptx

* 使用 Output Compare Match 的方式來執行中斷 (看影片聽講解比較快懂 https://www.youtube.com/watch?v=n0MNraPWQYo)

* 如何計算OCR0X (Output Compare Register)
  - Arduino Uno的系統時脈(system clock)為16MHz，1秒tick 16,000,000次，反過來說1個tick只要62.5ns(1/16,000,000)
  - 如果要從0數到255 (timer0 is a 8-bit timer)就需要16000ns(256/16,000,000)
  - 以上對我們來說都"太快了"，如果我們需要1ms中斷一次要怎麼實現?
  - 首先用prescale先降速，選64MHz，16,000,000Hz / 64 = 250,000Hz，反過來說1個tick要400ns (1/250,000 = 0.000004 second to increment once)
  - 0.001s = x * 0.000004s => x = 250 => 249 (因為是從0開始數所以要-1)
  - 就設成OCR0A = 249
  - prescale要慎選，如果最後結果超過255，就要選用timer1 (timer1 is a 16-bit timer)

* 另一個計算OCR0X範例
  - 如果我們要1秒中斷一次
  - 16,000,000 / 1024 = 15625Hz (1/15625 = 0.000064 second to increment once)
  - 1s = x * 0.000064s => x = 15625 => 15624
  - 超過255選用timer1

* 中斷參考網址
  - https://www.robotshop.com/letsmakerobots/arduino-101-timers-and-interrupts
  - http://www.instructables.com/id/Arduino-Timer-Interrupts/
