import numpy as np
import matplotlib.pyplot as plt

v = np.linspace(-0.1,0.1,50000)
a = [4,2,1]
b = [0.5,1,2]

y1 = a[0] * v**2 * np.sin(b[0]/v)
y2 = a[1] * v**2 * np.sin(b[1]/v)
y3 = a[2] * v**2 * np.sin(b[2]/v)

for x in np.arange(0,len(v)):
    if y2[x] > 0.003:
        y1[x] = 0.02
    if y2[x] < -0.003:
        y1[x] = -0.02

plt.figure()
plt.plot(v,y1)
plt.plot(v,y2)
plt.plot(v,y3)
plt.xlabel('x')
plt.ylabel('Wartości funkcji')
plt.legend(["x1","x2","x3"])
plt.show()

ysum = y2+y3
plt.figure()
plt.plot(v,ysum)
plt.xlabel('x')
plt.ylabel('y2+y3')
plt.show()



