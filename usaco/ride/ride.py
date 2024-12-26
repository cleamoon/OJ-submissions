"""
ID: yj1
LANG: PYTHON3
TASK: ride
"""
fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')

comet = fin.readline()
group = fin.readline()

print('1 ' + comet)
print('2 ' + group)

v1 = 1
v2 = 1

for c in list(comet)[:-1]:
    v1 = v1 * (ord(c) - ord('A') + 1)
for c in list(group)[:-1]:
    v2 = v2 * (ord(c) - ord('A') + 1)

print(v1 % 47)
print(v2 % 47)

if v1 % 47 == v2 % 47:
    fout.write('GO\n')
    fout.close
else:
    fout.write('STAY\n')
    fout.close
