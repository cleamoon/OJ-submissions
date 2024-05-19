cmp = 123456789

ans = set()

for i in range(1, 100):
    for j in range(i + 1, 10000):
        p = i * j
        l = list(str(i)) + list(str(j)) + list(str(p))
        if len(l) > 9:
            break
        if len(l) < 9:
            continue
        l.sort()
        if int(''.join(l)) == cmp:
            ans.add(p)

sum = 0

for n in ans:
    sum += n

print(sum)