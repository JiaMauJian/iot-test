* 看不懂這一段，accumulator >> 3是除以8的概念，這一段很像是移動平均法另一種寫法[How to calculate moving average without keeping the count and data-total?](https://stackoverflow.com/questions/12636613/how-to-calculate-moving-average-without-keeping-the-count-and-data-total)，但是對我而言不好理解
```
void tach_interrupt()
{
  ...
  // Accumulate the last 8 interrupt intervals
  accumulator -= (accumulator >> 3);
  accumulator += elapsed;
  ...
}
```
* 移動平均法的做法這段說的很清楚，If you want a moving average, just maintain N samples in a ring buffer. Together with the current total.
When you add a new sample, you adjust the total by subtracting the previous entry and adding the new entry to the total.
The average is always available as total/N.[link](http://www.avrfreaks.net/forum/looking-moving-average-code)

* 之前在玩ADC的時候有看過Arduino範例03.Analog->Smoothing，當時不太理解，現在回頭看就是移動平均法阿

* 能否將該作者移動平均法改成指數移動平均呢? (靈感來字Keras作者一書中p.83，要Smoothing Validation MAE)，指數移動平均的好處是計算過程只要前一點和目前這點的資料即可計算
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
