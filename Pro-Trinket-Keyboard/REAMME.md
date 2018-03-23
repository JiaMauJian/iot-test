* Arduino IDE
    * Board: Pro Trinket 5V/16MHz (USB)
    * Programmer: USBtinyISP
    
* 呼吸燈是bootloader mode，約維持十秒，表示可以燒錄程式

* 燈號閃爍三次表示找不到USBtiny裝置 (像我外接電池，按reset按鈕就會出現)

* 誤用pin 13，結果一直瘋狂輸出"A"，因為digitalRead都是LOW
    * https://www.arduino.cc/en/Tutorial/DigitalPins
    * NOTE: Digital pin 13 is harder to use as a digital input than the other digital pins because it has an LED and resistor attached to it that's soldered to the board on most boards. If you enable its internal 20k pull-up resistor, it will hang at around 1.7V instead of the expected 5V because the onboard LED and series resistor pull the voltage level down, meaning it always returns LOW. If you must use pin 13 as a digital input, set its pinMode() to INPUT and use an external pull down resistor.
    
