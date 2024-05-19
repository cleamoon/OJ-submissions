import itertools

lim = 10001

tb = [[False for _ in range(lim)] for _ in range(0, 6)]

for i in range(1, 200):
    a = i * (i + 1) // 2
    b = i * i 
    c = i * (3 * i - 1) // 2
    d = i * (2 * i - 1)
    e = i * (5 * i - 3) // 2
    f = i * (3 * i - 2)
    if a < lim:
        tb[0][a] = True
    if b < lim:
        tb[1][b] = True
    if c < lim:
        tb[2][c] = True
    if d < lim:
        tb[3][d] = True
    if e < lim:
        tb[4][e] = True
    if f < lim:
        tb[5][f] = True
    
l = [0, 1, 2, 3, 4, 5]

perm = itertools.permutations(l)

for p in perm:
    for a in range(1000, 10000):
        if tb[p[0]][a]:
            at = a % 100
            if at < 10:
                continue
            for b in range(100 * at, 100 * at + 100):
                if tb[p[1]][b]:
                    bt = b % 100
                    if bt < 10:
                        continue
                    for c in range(100 * bt, 100 * bt + 100):
                        if tb[p[2]][c]:
                            ct = c % 100
                            if ct < 10:
                                continue
                            for d in range(100 * ct, 100 * ct + 100):
                                if tb[p[3]][d]:
                                    dt = d % 100
                                    if dt < 10:
                                        continue
                                    for e in range(100 * dt, 100 * dt + 100):
                                        if tb[p[4]][e]:
                                            et = e % 100
                                            if et < 10:
                                                continue
                                            for f in range(100 * et, 100 * et + 100):
                                                if tb[p[5]][f]:
                                                    if f % 100 == a // 100 and len(set([a, b, c, d, e ,f])) == 6:
                                                        print(a + b + c + d + e + f)
                                                        exit()
