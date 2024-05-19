import math

s = 0

for n in range(3, 10000000):
    ns = sum(list(math.factorial(int(x)) for x in list(str(n))))
    if ns == n:
        s += n

print(s)