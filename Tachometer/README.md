* [Tachometer](https://learn.adafruit.com/pro-trinket-tachometer?view=all)，用QRD1114代替文中使用的Sensor

* 反射式Sensor(QRD1114)的距離很重要，規格中在Sensor離物體約距離[0.75mm](https://cdn.sparkfun.com/assets/learn_tutorials/5/1/6/measured-voltage.png)的時候，黑白切換的時候最有FALLING的效果(4.2V->0.8V)

* 我在TA350DC的風扇上貼了一個小轉盤(黑色)+雙面膠(白色)，來測試Tachometer

* 在看這隻程式的時候，應該先去看TA350DC那隻程式，了解RPM怎麼計算

* Tachometer作者的算法，我看了很久，覺得越看越有趣，後來才知道是moving average，而且他用 xxx >> 3來表示除以8，很有C語言風

* 後來在Stack Overflow上找到這篇很像作者使用的方法[link](how-to-calculate-moving-average-without-keeping-the-count-and-data-total)

```
                                                                  類比
double approxRollingAverage (double avg, double new_sample) {     ===>    void tach_interrupt() {

    avg -= avg / N;                                               ===>       accumulator -= (accumulator >> 3);
    avg += new_sample / N;                                        ===>       accumulator += elapsed; //在loop迴圈中計算rpm的時候才去除以N

    return avg;
}                                                                 ===>    }


                                                                  ===>    void loop() {
                                                                                      ...
                                                                  ===>        rpm = 60000000 / (accumulator>>3);
                                                                                      ... 
                                                                  ===>    }
```

* 這種計算移動平均的方法真的很神奇

* EXCEL檔案有試算一版
