import matplotlib.pyplot as plt
import math
import time
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.animation as animation
import tkinter as tk
import _thread

centerx = 3
centery = 3
R = 5
speed = 0.33
timenow = 0
timeresultion = 0.04
obspos = np.zeros((4,2))
X = np.arange(-10, 10, 0.75)
Y = np.arange(-10, 10, 0.75)
X, Y = np.meshgrid(X, Y)

dX = X - centerx
dY = Y - centery

def getobspos(idx, timenow):
    omega = speed / R
    arc = (omega * timenow + idx * (math.pi / 2)) % (2 * math.pi)
    return R * math.cos(arc), R * math.sin(arc)


#def attract(x,y,centerx,centery):
#    return 0.03 * ((x - centerx) ** 2 + (y - centery) ** 2)
def getattract():
    attract = 0.03 * (dX ** 2 + dY ** 2)
    return attract


def reject(x,y,xpos,ypos):
    ans=[]
    tab1 = np.sqrt((x - xpos) ** 2 + (y - ypos) ** 2)
    tab2 = 0.2 * (1 / tab1 - 1 / 2) ** 2 * ((x - centerx) ** 2 + (y - centery) ** 2)
    for i in range(27):
        ansy=[]
        for j in range(27):
            if (tab1[i][j]) > 2:
                ansy.append(0)
            else:
                ansy.append(tab2[i][j])
        ans.append(ansy)
    return ans

fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')

new_t = 0
old_t = 0

def animate(i):
    global timenow
    global new_t
    global old_t
    new_t = time.time()
    interval = new_t - old_t
    old_t = new_t
    time.sleep(timeresultion)
    timenow += timeresultion
    tic = time.time()
    #print(timenow)
    Z = getattract()
    #print(centerx, centery)
    for idx in range(4):
        obspos[idx][0], obspos[idx][1] = getobspos(idx, timenow)
        #print(obspos[idx][0], obspos[idx][1])
        #ax.plot([obspos[idx][0], obspos[idx][1]], 'ro')
        Z += reject(X,Y,obspos[idx][0],obspos[idx][1])
    ax.clear()
    toc = time.time()
    ax.set_title('Time:' + str(timenow) + '\n' + 'FPS' + str(1.0/interval) + '\n' + 'CalcRate:' + str(1.0/(toc - tic)))
    ax.plot_surface(X, Y, Z, cmap='terrain', vmax = 5)
    ax.view_init(90, 0)


def inputTarget(a,b):
    global centerx
    global centery
    global dX
    global dY
    while True:
        centerx, centery = map(int, input().split())
        dX = X - centerx
        dY = Y - centery
        attract = 0.03 * (dX ** 2 + dY ** 2)


try:
    _thread.start_new_thread(inputTarget,(0,1))
except:
    print("ERROR THREADING")
ani = animation.FuncAnimation(fig, animate, interval=10)
plt.show()

#Z = attract(X, Y) + reject(X, Y, 5, 0) + reject(X, Y, -5, 0) + reject(X, Y, 0, -5) + reject(X, Y, 0, 5)
#Z1 = f1(X, Y) / f2(X, Y)
#ax.plot_surface(X, Y, Z, cmap='terrain', vmax = 5)
#ax.plot_surface(X, Y, Z1, cmap='terrain')
#ax.plot_surface(X, Y, Z2)
#ax.plot([3, 10],[3, -6],'ro')
#print(len(sys.argv))
#if (len(sys.argv) == 1):
#    show()
#else:
#    savefig("Figure_5.eps")
