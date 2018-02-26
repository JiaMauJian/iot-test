* 步驟
1. Arduino IDE安裝ATtiny板子 (檔案 > 偏好設定 - 額外的開發版管理員網址) [參考網址](http://highlowtech.org/?p=1695)
2. 為了要把Arduino Uno當燒錄器，首先把Arduino Uno改成ISP，開啟範例燒錄進去 (檔案 > 範例 > ArduinoISP)
3. 可以修改ATtiny85預設為1 MHz的clock，Arduino IDE > 工具，<<<這裡的選項很重要>>>，開發版選ATtiny85，處理器選ATtiny85，Clock選internal 8 MHz，燒錄器選Arduino as ISP
4. 開Blink的範例，改用pin 0，燒錄後完成

* 問題
1. platformio燒錄ATtiny85試不出來，改用Arduino IDE

* 電容
1. 為什麼要加一顆電容?
- [關閉 Arduino UNO 的 auto reset](http://coopermaa2nd.blogspot.tw/2013/09/arduino-uno-auto-reset.html)
- [Auto Reset](http://pizgchen.blogspot.tw/2014/04/arduino-reset.html)
2. 我試過1uF的電容或是不加也可以
3. 從示波器觀察reset腳位是HIGH(5V)，當開啟Serial Port時，HIGH會從LOW再到HIGH，而reset觸發的時機點是從LOW變HIGH時，因此加個電容就是有意讓它沒機會變LOW.
4.電容有電池的概念在，但還是有差異(https://www.youtube.com/watch?v=LNci-13Bp1U)
