# Port Registers
* [Port Registers](https://www.youtube.com/watch?v=648Tx5N9Zoc&t=4s)
* [Probe接法](https://github.com/JiaMauJian/iot-test/blob/master/Port%20Registers/probe%20pin13.jpg?raw=true)
* [Arduino Uno Rev3 Schematic 電路圖](https://www.arduino.cc/en/uploads/Main/Arduino_Uno_Rev3-schematic.pdf)
* [從 Arduino 到 AVR 晶片](http://programmermagazine.github.io/201406/htm/article1.html)

# USART
* [AVR USART (Serial Communication) Explained](https://www.youtube.com/watch?v=KnyyQujvcBo)
* [Serial Communications -- USART](https://www.youtube.com/watch?v=W5xt6w5EMP0)
* [Using the ATmega328P registers](https://www.youtube.com/watch?v=8aMsJWpXyE8)

#備註
* 若要像影片中示波器顯示的波型[Using the ATmega328P registers](https://www.youtube.com/watch?v=8aMsJWpXyE8)，要用Serial.write()而不是Serial.print()
* [Write說明:](https://www.arduino.cc/en/Serial/Write)Writes binary data to the serial port. This data is sent as a byte or series of bytes; to send the characters representing the digits of a number use the print() function instead. write()是寫binary data，print()是輸出字元
* [示波器結果](https://github.com/JiaMauJian/iot-test/blob/master/Port%20Registers/registers.jpg?raw=true)
