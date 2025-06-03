tl = {}

for i in range(1, 1000000):
    c = i * i * i
    sl = sorted(list(str(c)))
    s = ''.join(sl)
    if s in tl:
        tl[s][1] += 1
        if tl[s][0] > c:
            tl[s][0] = c
    else:
        tl[s] = [c, 1]

mincub = 1e50

for k in tl:
    if tl[k][1] == 5:
        if tl[k][0] < mincub:
            mincub = tl[k][0]

print(mincub)