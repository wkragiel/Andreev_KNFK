#main for visualisation
import numpy as np
from matplotlib.animation import FuncAnimation
import matplotlib.animation as animation
import matplotlib.pyplot as plt
import read2 as read

time, z, r = read.readfilePos("pos3.csv")


#for i in time:
#    print(z.loc[i])
ar1 = z.loc[0]
ar2 = r.loc[0]

x=[]
y=[]

fig,ax = plt.subplots()
ax.set_xlabel("X coordinates")
ax.set_ylabel("Y coordinates")
ax.set_title("Localisation of particles in box")

#fig.savefig('nothing') #for saving xd

def animate(i):
    if i < len(time):
        first = z.loc[i].to_numpy()
        second = z.loc[i].to_numpy()
        first = [float(numeric_string) for numeric_string in first]
        second = [float(numeric_string) for numeric_string in second]
        ax.clear()
        ax.scatter(first,second)
    else:
        i==0

ani = FuncAnimation(fig,animate, frames=20, interval=500, repeat = True)
plt.show()

