import numpy as np
import matplotlib.pyplot as plt
import math

def ewa_init_first_sample(points, factor=0.9):
    smoothed_points = []
    for point in points:
        if smoothed_points:
            previous_point = smoothed_points[-1]
            smoothed_points.append(previous_point * factor + point * (1 - factor))
        else:
            smoothed_points.append(point)

    return smoothed_points

def ewa_init_zero(points, factor=0.9):
    smoothed_points = []
    for point in points:
        if smoothed_points:
            previous_point = smoothed_points[-1]            
        else:
            previous_point = 0

        smoothed_points.append(previous_point * factor + point * (1 - factor))        
        
    return smoothed_points

def ewa_init_bias_correction(points, factor=0.9):
    smoothed_points = []
    smoothed_points_with_bias_corr = []
    bias = 1
    for point in points:
        if smoothed_points:
            previous_point = smoothed_points[-1]            
        else:
            previous_point = 0

        bias = bias * factor
        ewa = previous_point * factor + point * (1 - factor)
        #print ewa / (1-bias)
        smoothed_points.append(ewa) #我debug很久的地方，因為我把ewa / (1-bias)存進去導致結果錯誤 (X)smoothed_points.append(ewa/(1-bias))
        smoothed_points_with_bias_corr.append(ewa / (1-bias)) # bias corr的結果要另外存，避免影響到ewa的計算
    return smoothed_points_with_bias_corr

with open('data1.txt') as f:
    lines = f.read().splitlines()

data = [float(x) for x in lines]

factor = 0.98
ewa1 = ewa_init_first_sample(data, factor)
ewa2 = ewa_init_zero(data, factor)
ewa3 = ewa_init_bias_correction(data, factor)

plt.plot(range(1, len(data)+1), data, 'b.', label='data')
plt.plot(range(1, len(ewa1)+1), ewa1, 'r', label='factor = ' + str(factor) + ' (init by first sample)')
plt.plot(range(1, len(ewa2)+1), ewa2, 'g', label='factor = ' + str(factor) + ' (init by zero)')
plt.plot(range(1, len(ewa3)+1), ewa3, 'y', label='factor = ' + str(factor) + ' (init by bias-correction)')
plt.title('Exponentially Weighted Averages')
plt.legend()
plt.show()
