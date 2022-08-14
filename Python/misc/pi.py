from math import *

an = 0
power2 = 1/2
power3 = 1/3
for n in range(100):
    an += (power2+power3)/(4*n+1) - (power2/4 + power3/9)/(4*n+3)
    power2 /= 16
    power3 /= 81
    if n%10 == 9:
        print(4*an)
