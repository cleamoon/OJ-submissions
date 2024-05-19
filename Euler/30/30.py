s = 0
for i in range(10, 500000):
    ls = list(str(i))
    ns = 0
    for j in ls:
        ns += int(j)**5
    if ns == i:
        s += ns

print(s)