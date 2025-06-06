"""
ID: yj1
LANG: PYTHON3
TASK: gift1
"""
fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')

n = int(fin.readline())

names = []
account = {}

for i in range(n):
    names.append(fin.readline().rstrip('\n'))
    account[names[-1]] = 0

for i in range(n):
    giver = fin.readline().rstrip('\n')
    total, nReceiver = map(int, fin.readline().split())
    account[giver] -= total
    if nReceiver == 0:
        continue
    gift = total // nReceiver
    left = total  % nReceiver
    account[giver] += left
    for j in range(nReceiver):
        receiver = fin.readline().rstrip('\n')
        account[receiver] += gift
    
for i in range(n):
    fout.write(names[i] + ' ' + str(account[names[i]]) + '\n')

fout.close()

