"""
ID: yj1
LANG: PYTHON3
TASK: milk2
"""
fin = open ('milk2.in', 'r')
fout = open ('milk2.out', 'w')
n = int(fin.readline())

times = []

for i in range(n):
    b, e = map(int, fin.readline().split())
    times.append([b, 1])
    times.append([e, -1])

times.sort(key = lambda x: x[0])

for i in reversed(range(len(times)-1)):
    if times[i][0] == times[i+1][0] and times[i][1]+times[i+1][1] == 0:
        times.pop(i+1)
        times.pop(i)

curr = 0
nodes = []

for i in times:
    curr += i[1]
    nodes.append([i[0], curr])


max_milk = 0
max_idle = 0

i = 0
while i < len(times)-1:
    if nodes[i][1] == 0:
        if nodes[i+1][0] - nodes[i][0] > max_idle:
            max_idle = nodes[i+1][0] - nodes[i][0]
    else:
        for j in range(i+1, len(nodes)):
            if nodes[j][1] == 0:
                if nodes[j][0] - nodes[i][0] > max_milk:
                    max_milk = nodes[j][0] - nodes[i][0]
                    i = j-1
                break
    i += 1

fout.write (str(max_milk) + ' ' + str(max_idle) + '\n')
fout.close()

