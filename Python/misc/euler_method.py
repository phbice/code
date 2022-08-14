# -*- coding: utf-8 -*-
"""
Created on Sat Mar 14 19:52:25 2020

@author: hp2017
"""
import matplotlib.pyplot as plot

maxDy = 1e-3
maxDt = 1e-3
n = 4
a = 10
omega = 6.283

ylist = [ [0.01, 0] ]
tlist = [0]
def diffY(y):
    dy = y[1]
    ddy = a - omega**2 * y[0]
    return [dy,ddy]

def deltaT(dy):
    return maxDy / max (dy + [maxDy / maxDt])

t = 0
y = ylist[-1]
while t <= 10:
    dy = diffY(y)
    dt = deltaT(dy)
    y = list(map(lambda yi,dyi: yi + dyi*dt, y, dy))
    t += dt
    ylist.append(y)
    tlist.append(t)

plot.scatter(tlist, [y[0] for y in ylist])
