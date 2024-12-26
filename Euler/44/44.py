import math

lim = 10000000

num = [False for _ in range(0, lim)]

for i in range(1, lim):
    t = i * (3 * i - 1) // 2
    if t < lim:
        num[t] = True

mind = 1000000000

lpn = []

for i in range(1, lim):
    if num[i]:
        lpn.append(i)

for i in range(1, len(lpn)):
    for j in range(i + 1, len(lpn)):
        cd = lpn[j] - lpn[i]
        cs = lpn[j] + lpn[i]
        if cs < lim and num[cd] and num[cs]:
            if cd < mind:
                mind = cd

print(mind)