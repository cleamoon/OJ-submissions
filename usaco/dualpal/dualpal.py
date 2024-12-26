"""
ID: yj1
LANG: PYTHON3
TASK: dualpal
"""
fin = open ('dualpal.in', 'r')
fout = open ('dualpal.out', 'w')
n, u = map(int, fin.readline().split())

def trans(n, b):
    res = []
    while n != 0:
        res.append(str(n%b))
        n = n//b
    return list(reversed(res))

f = 0
for i in range(u+1, 10000000):
    ff = 0
    for j in range(2,11):
        t = trans(i, j)
        if t == list(reversed(t)):
            ff += 1
        if ff == 2:
            fout.write(str(i) + '\n')
            f += 1
            break
    if f == n:
        break

fout.close()

