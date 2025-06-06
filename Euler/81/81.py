s = 80

m = [[1000*80*80*10000 for _ in range(s)] for _ in range(s) ]

with open("mat.txt") as f:
    lines = f.readlines()

d = []

for line in lines:
    d.append([int(x) for x in line.split(',')])

m[0][0] = d[0][0]

for i in range(80):
    for j in range(80):
        if i > 0:
            m[i][j] = min(m[i][j], m[i-1][j] + d[i][j])
        if j > 0:
            m[i][j] = min(m[i][j], m[i][j-1] + d[i][j])

print(m[80-1][80-1])