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
02_FlashWithoutDelay.cpp，這是另一種狀態改變的手法，可依照狀態時間長短改變，如亮個250ms，暗個750ms

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
