from math import sin
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig, ax = plt.subplots()

data = np.genfromtxt(open('datafile.csv'))
linelength = len(data[1]) #data assumed rectangular
filelength = len(data)

x = np.arange(linelength)
line, = ax.plot(data[1])

def animate(i):
    line.set_ydata(data[i])  # update the data
    return line,

#Init only required for blitting to give a clean slate.
def init():
    y=np.ma.array(x, mask=True)
    line.set_ydata(y)
    #plt.fill(x, y, 'r')
    return line,

ani = animation.FuncAnimation(fig, animate, np.arange(0, filelength), init_func=init,
    interval=25, blit=True)
plt.show()
