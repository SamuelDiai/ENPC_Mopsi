import wrap
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
def test_():
    return wrap.simulate()


if __name__ == '__main__':
    T = test_()
    
    def fonction(x,y):
        return np.sin(y)*np.cos(x)
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    
    A = [T[i][0] for i in range(len(T))]
    B = [T[i][1] for i in range(len(T))]
    L = [fonction(T[i][0],T[i][1]) for i in range(len(T))]
    
    X = np.arange(-10, 10, 0.02)
    Y = np.arange(-10, 10, 0.02)
    X, Y = np.meshgrid(X, Y)
    Z = fonction(X, Y)
    ax.plot_surface(X, Y, Z)
    ax.plot(A[:500] ,B[:500],L[:500])
    plt.show()

