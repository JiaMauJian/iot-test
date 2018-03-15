* Arduino IDE安裝STM32版子 [link](http://wiki.stm32duino.com/index.php?title=Boards_Manager_package)

* STM32燒錄 : 切jump後，拿一條FTDI的線，(沒有接電源，mini usb記得插上供電)
    * TX <-> A10
    * RX <-> A9
    * GND <-> GND

* 燒錄Pro Trinket也是一樣的線路，燒錄前要按一下reset進入呼吸燈狀態才可燒錄

* [PinOut腳位](http://wiki.stm32duino.com/index.php?title=File:Bluepillpinout.gif)

* PWM (16-bit)
```
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PA8, PWM);
}

void loop() {
  // put your main code here, to run repeatedly:
  pwmWrite(PA8, 32768); //void pwmWrite(uint8 pin, uint16 duty_cycle)
}
```
![alt text](https://github.com/JiaMauJian/iot-test/blob/master/STM32/pwm.jpg?raw=true)

* 為什麼PWM頻率只有549.5(Hz)，因為T1C1預設值影響到PA8 (看PinOut)
