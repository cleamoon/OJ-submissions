lim = 28124
anl = []
for n in range (2, lim):
    ds = 0
    for m in range(1, n):
        if n % m == 0:
            ds += m
    if ds > n:
        anl.append(n)

snl = [False for _ in range(lim)]

for i in anl:
    for j in anl:
        if i + j < lim:
            snl[i + j] = True

ans = 0

for i in range(lim):
    if (not snl[i]):
        ans += i


print(ans)
