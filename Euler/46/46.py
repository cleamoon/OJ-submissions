import math

lim = 10000

num = [True for _ in range(lim)]

for i in range(4, lim, 2):
    num[i] = False

for i in range(3, lim, 2):
    for j in range(i * i, lim, 2 * i):
        num[j] = False

gbn = [True for _ in range(lim)]

for i in range(3, lim, 2):
    if num[i]:
        for j in range(0, lim, 1):
            n = i + 2 * j * j
            if n > lim:
                break
            gbn[n] = False

for i in range(3, lim, 2):
    if gbn[i]:
        print(i)
        exit()