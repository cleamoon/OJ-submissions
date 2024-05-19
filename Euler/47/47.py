lim = 10000000

num = [0 for _ in range(lim)]

for i in range(4, lim, 2):
    num[i] += 1

for i in range(3, lim, 2):
    if num[i] == 0:
        for j in range(i + i, lim, i):
            num[j] += 1

for i in range(2, lim):
    found = True
    for j in range(0, 4):
        if num[i + j] != 4:
            found = False
            break
    if found:
        print(i)
        break