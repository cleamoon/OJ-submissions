lim = 10000000

num = [True for _ in range(lim)]

for i in range(4, lim, 2):
    num[i] = False

for i in range(3, lim, 2):
    if num[i]: 
        for j in range(i * i, lim, i):
            num[j] = False

oa = 0
ob = 0
mnp = 0

size = 1000

for a in range(-size + 1, size):
    for b in range(1, size, 2):
        np = 0
        for n in range(0, lim):
            if num[n * n + a * n + b]:
                np += 1
            else:
                break
        if np > mnp:
            mnp = np
            oa = a
            ob = b

print(oa * ob)