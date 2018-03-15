# 實驗版 : Mega 2560

# 說明
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

* 這種計算移動平均的方法真的很神奇，EXCEL檔案有試算一版

* 另一種寫法就是用矩陣的方式去計算移動平均，之前在玩ADC的時候有看過Arduino範例03.Analog->Smoothing，當時不太理解，現在回頭看就是移動平均法阿

* 能否將該作者移動平均法改成指數移動平均呢? (靈感來字Keras作者一書中p.83，要Smoothing Validation MAE)
```
def smooth_curve(points, factor=0.9):
  smoothed_points = []
  for point in points:
    if smoothed_points:
      previous = smoothed_points[-1]
      smoothed_points.append(previous * factor + point * (1 - factor))
    else:
      smoothed_points.append(point)
  return smoothed_points
```

# Andrew Ng對於Exponentially Weighted averages有更好的解釋
* [58. Exponentially Weighted Averages](https://www.youtube.com/watch?v=wJBcz7FyLzg&list=PLBAGcD3siRDguyYYzhVwZ3tLvOyyG5k6K&index=58)
    * 這真的很有趣，我們可以用Beta可以用來反推是幾筆取一次平均
```
n = 1/1-Beta, Beta = 0.9, n = 10筆取一次平均
```
    * 原來如此，影片最後有推導出e (我圖片只說了一半)
![alt text](https://github.com/JiaMauJian/iot-test/blob/master/Tachometer/EWA.png?raw=true)
