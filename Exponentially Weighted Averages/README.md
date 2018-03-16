* 當初在弄Tachometer(iot-test/Tachometer)的時候，研究了作者的程式，才知道作者是採用moving average來得到一個穩定的數值，所以後來才有個想法說，用Keras作者書中(Deep Learning with Python Keras, p.83)的提到指數平均法，是否也能得到一個穩定的數值?

* 之前不太懂指數平均法的概念，只知道調factor(也有叫alpha, beta反正就是這個EWA有一個參數可以調)，但後來看見Andrew Ng在Youtube上Deep Learning的課程介紹Exponentially Weighted averages(EWA)，才發現他真的講得很清楚，甚至看完才了解當初李宏毅老師講的RMSprop、Adam都有EWA的精神

* [58. Exponentially Weighted Averages](https://www.youtube.com/watch?v=wJBcz7FyLzg&list=PLBAGcD3siRDguyYYzhVwZ3tLvOyyG5k6K&index=58)

1. 這真的很有趣，我們可以用Beta可以用來反推是幾筆取一次平均
```
n = 1/1-Beta, Beta = 0.9, n = 10筆取一次平均
```

