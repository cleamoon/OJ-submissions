import math

maxb = 1
maxe = 1
maxl = 0
max = 0
curl = 0

with open("base_exp.txt") as f:
    lines = f.readlines()

for line in lines:
    ls = line.split(',')
    curl += 1
    b, e = int(ls[0]), int(ls[1])
    if e == 0:
        cur = 1.0
    elif e == 1:
        cur = float(b)
    else:
        cur = e * math.log(b)

    if cur > max:
        maxb, maxe, max, maxl = b, e, cur, curl


print(maxl)


