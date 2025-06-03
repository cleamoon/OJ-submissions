lim = 100000000
num = [True for _ in range(lim)]
pri = [2]

for i in range(4, lim, 2):
    num[i] = False

for i in range(3, lim, 2):
    if num[i]:
        pri.append(i)
        for j in range(i*i, lim, 2*i):
            num[j] = False

lngth = 0
ans = 0

for i in range(len(pri)):
    if pri[i] > 1000000:
        break
    for j in range(len(pri) - i):
        s = sum(pri[i:i+j])
        if s > 1000000:
            break
        if num[s] and j > lngth:
            lngth = j
            ans = s

print(ans)
