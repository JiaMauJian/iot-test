import numpy as np
import matplotlib.pyplot as plt
import math

def ewa(points, factor=0.9):
    smoothed_points = []
    for point in points:
        if smoothed_points:
            previous_point = smoothed_points[-1]
            smoothed_points.append(previous_point * factor + point * (1 - factor))
        else:
            smoothed_points.append(point)

    return smoothed_points

with open('data.txt') as f:
    lines = f.read().splitlines()

data = [float(x) for x in lines]

ewa_data9 = ewa(data)
ewa_data98 = ewa(data, 0.98)
ewa_data5 = ewa(data, 0.5)

plt.plot(range(1, len(data)+1), data, 'b.', label='data')
plt.plot(range(1, len(ewa_data9)+1), ewa_data9, 'r', label='factor = 0.9 (same as avg n=10)')
plt.plot(range(1, len(ewa_data98)+1), ewa_data98, 'g', label='factor = 0.98 (same as avg n=50)')
plt.plot(range(1, len(ewa_data5)+1), ewa_data5, 'y', label='factor = 0.5 (same as avg n=2)')
plt.title('Exponentially Weighted Averages')
plt.legend()
plt.show()
