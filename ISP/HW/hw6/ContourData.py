import numpy as np
import matplotlib.pyplot as plt

array = np.loadtxt('/Users/JCHAO/Documents/UT/YEAR6/ISP/HW/hw6/contourData.dat.txt')
plt.pcolormesh(array, cmap = 'YlOrRd_r')
plt.colorbar()
plt.title('Contour Data')
plt.xlabel("X")
plt.ylabel("Y")
plt.show()
