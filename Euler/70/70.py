lim = 10000000 + 1

isPrime = [True for _ in range(0, lim)]

for i in range(2, lim):
    if isPrime[i]:
        j = i * i
        while True:
            if j > lim - 1:
                break
            isPrime[j] = False
            j += 2 * i
    
prfac = [[] for _ in range(0, lim)]

for i in range(2, lim):
    if isPrime[i]:
        for j in range(i, lim, i):
            prfac[j].append(i)

toti = [x for x in range(0, lim)]

for i in range(2, lim):
    for p in prfac[i]:
         toti[i] *= (p - 1)   
         toti[i] //= p

perm = []

for i in range(2, lim):
    s1 = str(''.join(sorted(list(str(i)))))
    s2 = str(''.join(sorted(list(str(toti[i])))))
    if s1 == s2:
        perm.append(i)

mind = lim
ans = 0

for i in perm:
    d = float(i) / float(toti[i])
    if d < mind:
        mind = d
        ans = i

print(ans)