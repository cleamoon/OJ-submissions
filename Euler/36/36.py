s = 0

for n in range(1, 1000001):
    ln  = list(str(n))
    lnr = ln.copy()
    lnr.reverse()

    if (ln != lnr):
        continue
    bl = []
    t = n
    while t != 0:
        bl.append(t % 2)
        t //= 2
    blr = bl.copy()
    blr.reverse()
    if blr != bl:
        continue
    s += n

print(s)