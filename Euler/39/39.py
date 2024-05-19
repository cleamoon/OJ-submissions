mp = 0
mn = 0

for lim in range (5, 1001):
    ts = set()
    for x in range(1, lim//2 + 1):
        for y in range(x, lim//2 + 1):
            [a, b, c] = sorted([x, y, lim - x -y])
            if a + b <= c:
                continue
            if a * a + b * b == c * c:
                ts.add((a, b, c))
    if len(ts) > mn:
        mn = len(ts)
        mp = lim

print(mp)