* [腳位介紹](https://tutorials.webduino.io/zh-tw/docs/basic/board/smart-information.html)

* 不使用Webduino Blockly，改用Arduino IDE開發
1. Arduino IDE安裝ESP8266板子(https://github.com/esp8266/Arduino)
2. 使用USB TTL線燒錄程式 [image](https://github.com/JiaMauJian/iot-test/blob/master/Webduino/%E7%87%92%E9%8C%84%E6%A8%A1%E5%BC%8F.jpg?raw=true)
3. [config](https://github.com/JiaMauJian/iot-test/blob/master/Webduino/config.png?raw=true)
4. 先確認Flash Size，使用Examples -> ESP8266 -> CheckFlashConfig (Webduino這塊Flash Size是4M (3M SPIFFS)，搞定Flash才有辦法用Wifi燒錄，不然會出現Space Not Enough錯誤)
```
Flash real id:   001640EF
Flash real size: 4194304

Flash ide  size: 4194304
Flash ide speed: 40000000
Flash ide mode:  QIO
Flash Chip configuration ok.

```
5. 用BasicOTA測試[程式](https://github.com/JiaMauJian/iot-test/blob/master/Webduino/BasicOTA.ino)

* ref
    * http://www.cnblogs.com/sjqlwy/p/smart_all_in_1.html
