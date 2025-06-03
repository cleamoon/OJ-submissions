lim = 1000001

table = [1 for _ in range(lim)]

primesT = [True for _ in range(lim)]

for i in range(4, lim, 2):
    primesT[i] = False

for i in range(3, lim):
    for j in range(i*i, lim, i):
        primesT[j] = False

prime = []

for i in range(2, len(primesT)):
    if primesT[i]:
        prime.append(i)

for i in prime:
    for j in range(i, lim, i):
        table[j] /= (1 - 1 / i)

print(table.index(max(table)))