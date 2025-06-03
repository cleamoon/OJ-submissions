maxs = 0

for i in range(2, 101):
    for j in range(1, 101):
        s = 0
        cs = list(str(i ** j))
        for c in cs:
            s += ord(c)-ord('0')
        if s > maxs:
            maxs = s

print(maxs)