l = []

lim = 2000000

for i in range(1, lim):
    ci = i * (i + 1) // 2
    if ci > lim:
        break
    l.append(ci)

area = 0
diff = lim

for i in l:
    for j in l:
        if i * j > 2 * lim:
            break
        cd = abs(lim - i * j)
        if cd < diff:
            diff = cd
            area = (l.index(i) + 1) * (l.index(j) + 1)

print(area)