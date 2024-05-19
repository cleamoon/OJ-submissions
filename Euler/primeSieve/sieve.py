lim = 10000000000
num = [True for _ in range(lim)]

for i in range(4, lim, 2):
    num[i] = False

for i in range(3, lim, 2):
    if num[i]:
        for j in range(i*i, lim, 2*i):
            num[j] = False