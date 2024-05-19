from sympy import *

for n in range(1, 1000000):
    np = partition(n)
    if np % 1000000 == 0:
        print(n)
        break