# -*- coding: utf-8 -*-
"""
Created on Thu Oct 10 17:21:40 2019

@author: fm160576d
"""


from scipy.optimize import minimize
import numpy as np
import matplotlib.pyplot as plt

from math import pi

file = open("Zadatak.txt", "r")
values = list()
deltas = [i*pi/50 for i in range(0,100)]
for line in file:
    values.append(float(line))
    
plt.figure()
plt.plot(deltas, values)
plt.xlabel("D")
plt.ylabel("moduo")

maxV = max(values)
maxi = list()
for i in range (0,100):
    if (values[i] == maxV):
        maxi.append(deltas[i])
        
print(maxV)
print(maxi) 
