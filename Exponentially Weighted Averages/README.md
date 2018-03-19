* 當初在弄Tachometer(iot-test/Tachometer)的時候，研究了作者的程式，才知道作者是採用moving average來得到一個穩定的數值，所以後來才有個想法說，用Keras作者書中(Deep Learning with Python Keras, p.83)的提到指數平均法，是否也能得到一個穩定的數值?

* 之前不太懂指數平均法的概念，只知道調factor(也有叫alpha, beta反正就是這個EWA有一個參數可以調)，但後來看見Andrew Ng在Youtube上Deep Learning的課程介紹Exponentially Weighted averages(EWA)，才發現他真的講得很清楚，甚至看完才了解當初李宏毅老師講的RMSprop、Adam都有EWA的精神

* [58. Exponentially Weighted Averages](https://www.youtube.com/watch?v=wJBcz7FyLzg)

這真的很有趣，我們可以用Beta可以用來反推是幾筆取一次平均
```
n = 1 / 1-Beta, Beta = 0.9, n = 10筆取一次平均
```

* [59. Understanding Exponentially Weighted Averages](https://www.youtube.com/watch?v=WJb-QVd54vw)

原來Exponentially是這樣來的，還解釋了 n = 1 / 1-Beta是怎麼來的
![alt text](https://github.com/JiaMauJian/iot-test/blob/master/Exponentially%20Weighted%20Averages/ewa.png?raw=true)

* [60. Bias Correction](https://www.youtube.com/watch?v=Zs4qJN-I5Kk)
會使用Bias Correction是在很Care初期EWA的預算結果，如果不Care初期幾筆運算的結果，也可以等跑個幾筆就跟原始EWA的運算結果一樣
