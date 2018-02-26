* 上傳ArduinoISP程式時，要先將Arduino板子上清空，等燒錄完成再接上ATtiny85其他線
* platformio燒錄ATtiny85試不出來，改用Arduino IDE
* [Programming an ATtiny85 with uno](https://www.youtube.com/watch?v=i9WOwDrpRKs)
* [(中文)使用 Arduino 燒錄 ATtiny](http://coopermaa2nd.blogspot.tw/2012/04/arduino-attiny.html)
* 為什麼要加一顆電容? (我試過1uF的電容也可以)
  - [關閉 Arduino UNO 的 auto reset](http://coopermaa2nd.blogspot.tw/2013/09/arduino-uno-auto-reset.html)
  - [Auto Reset](http://pizgchen.blogspot.tw/2014/04/arduino-reset.html)

* 從示波器觀察reset腳位是HIGH(5V)，當開啟Serial Port時，HIGH會從LOW再到HIGH，而reset觸發的時機點是從LOW變HIGH時，因此加個電容就是有意讓它沒機會變LOW

* 電容有電池的概念在，但還是有差異(https://www.youtube.com/watch?v=LNci-13Bp1U)
