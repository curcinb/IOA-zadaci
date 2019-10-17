from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np



fig = plt.figure()
ax = fig.gca(projection = '3d')

x = np.arange(-4, 4, 0.5)
y = np.arange(-4, 4, 0.5)
x, y = np.meshgrid(x, y)


c = [0.05, 0.1, 0.04, 0.1, 0.05]
a = [[-3, -3], [-1.5, -1.5],[0,0], [1.5, 1.], [3, 3]]

z = 0
K = 0.5

n = np.arange(5)
for i in n:
    z = z + ((x - a[i][0])**2 + (y - a[i][1])**2 + c[i])**(-1)
z = K - z

s = ax.plot_surface(x, y, z, cmap = plt.cm.RdYlGn)

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_facecolor('aqua')
plt.show()