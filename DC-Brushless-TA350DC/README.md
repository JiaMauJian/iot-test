# 實驗版 : Mega 2560

# 參考
* [Arduino: Read out and control a 4-pin CPU fan](http://www.beefrankly.org/blog/2011/12/21/read-out-4-pin-cpu-fan-speed/)，雖然文中是使用Intel DTC AAL03，但與TA350DC一樣都是每轉一圈產生兩個pulse

# 其他
* 接線圖
    ![alt text](https://raw.githubusercontent.com/JiaMauJian/iot-test/master/DC-Brushless-TA350DC/TA350DC.png)

* 示波器(轉速訊號)，這邊有個錯誤，頻率應該先除以pulse數，TA350DC的pulse數是2，freq = 42.45 / 2 = 21.23，RPM = 21.23 * 60 = 1274
![alt text](https://raw.githubusercontent.com/JiaMauJian/iot-test/master/DC-Brushless-TA350DC/TA350DC%E9%BB%83%E7%B7%9A%E8%BD%89%E9%80%9F%E8%A8%8A%E8%99%9F.jpg)

* 輸出結果，freq = 21.74
![alt text](https://raw.githubusercontent.com/JiaMauJian/iot-test/master/DC-Brushless-TA350DC/output.png)

# 程式說明 (請參考4wire_fan_ta350dc.ino)
* 頻率就是每秒幾次(圈)，那想像時鐘每分鐘(60秒)轉一圈經過60個刻度(次)，頻率就是60秒/60次=1Hz

* pulse duration是1秒

* 轉一圈是60個pulse，所以要60秒

* 頻率是每秒幾圈 => 1秒 / 轉一圈時間 = 1 / 60 => 0.0167Hz

* RPM是每分鐘幾轉 => 60 * frequency = 60秒 * 0.0167Hz = 1
