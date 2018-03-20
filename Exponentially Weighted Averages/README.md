* 當初在弄Tachometer(iot-test/Tachometer)的時候，研究了作者的程式，才知道作者是採用moving average來得到一個穩定的數值，所以後來才有個想法說，用Keras作者書中(Deep Learning with Python Keras, p.83)的提到指數平均法，是否也能得到一個穩定的數值?

* 之前不太懂指數平均法的概念，只知道調factor(也有叫alpha, beta反正就是這個EWA有一個參數可以調)，但後來看見Andrew Ng在Youtube上Deep Learning的課程介紹Exponentially Weighted averages(EWA)，才發現他真的講得很清楚，甚至看完才了解當初李宏毅老師講的RMSprop、Adam都有EWA的精神

* [58. Exponentially Weighted Averages](https://www.youtube.com/watch?v=wJBcz7FyLzg)
這真的很有趣，我們可以用Beta可以用來反推是幾筆取一次平均
```
n = 1 / 1-Beta, Beta = 0.9, n = 10筆取一次平均
```

* [59. Understanding Exponentially Weighted Averages](https://www.youtube.com/watch?v=WJb-QVd54vw)
原來Exponentially是這樣來的，還解釋了 n = 1 / 1-Beta是怎麼來的

* [60. Bias Correction](https://www.youtube.com/watch?v=Zs4qJN-I5Kk)
    * 會使用Bias Correction是在很Care初期EWA的預算結果，如果不Care初期幾筆運算的結果，也可以等跑個幾筆就跟原始(紫線)EWA的運算結果一樣
    * 紫線沒有使用Bias Correction，綠線有使用Bias Correction
    * In practice: most people don't bother to implement bias correction — just wait for the initial phase to warm up...
    * [Coursera | Andrew Ng (02-week-2-2.5)— 指数加权平均的偏差修正](http://blog.csdn.net/JUNJUN_ZHAO/article/details/79099040)

* Bias Correction實作一直有問題，後來參考這篇文章後[The correct way to start an Exponential Moving Average (EMA)](https://blog.fugue88.ws/archives/2017-01/The-correct-way-to-start-an-Exponential-Moving-Average-EMA)，才找到錯誤，請看程式內說明ewa/ewa2.py
    * 作者loop中計算extra <<- r*extra 其實就是計算beta^t
    * 最後1-extra就是1-beta^t

* 一種同除平均的概念??? (係數相加後等同分母的數值，有趣)
![alt text](https://github.com/JiaMauJian/iot-test/blob/master/Exponentially%20Weighted%20Averages/bias-correction.png)

* EMA計算方式
![alt text](https://github.com/JiaMauJian/iot-test/blob/master/Exponentially%20Weighted%20Averages/EMA%E8%A8%88%E7%AE%971.png)
* 看個影片了解一下[weighted average](https://www.youtube.com/watch?v=slFqL86q3EA)，底下EMA的公式也是這種概念
![alt text](https://github.com/JiaMauJian/iot-test/blob/master/Exponentially%20Weighted%20Averages/EMA%E8%A8%88%E7%AE%972.png)
