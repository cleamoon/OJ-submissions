"""
ID: yj1
LANG: PYTHON3
TASK: transform
"""
fin = open ('transform.in', 'r')
fout = open ('transform.out', 'w')
n = int(fin.readline())
ori = ['']*n
for i in range(n):
    ori[i] = list(str(fin.readline()).rstrip())

def rot90(ori, n):
    res = ['']*n
    for i in range(n):
        tmp = ['']*n
        for j in reversed(range(n)):
            tmp[n-j-1] = ori[j][i]
        res[i] = tmp
    return res

def rot180(ori, n):
    return rot90(rot90(ori, n), n)

def rot270(ori, n):
    return rot90(rot180(ori, n), n)

def reflex(ori, n):
    res = list(ori)
    for i in range(n):
        res[i] = list(reversed(res[i]))
    return res

cmp = ['']*n
for i in range(n):
    cmp[i] = list(str(fin.readline()).rstrip('\n'))

if cmp == rot90(ori, n):
    fout.write('1\n')
elif cmp == rot180(ori, n):
    fout.write('2\n')
elif cmp == rot270(ori, n):
    fout.write('3\n')
elif cmp == reflex(ori, n):
    fout.write('4\n')
elif cmp == rot90(reflex(ori, n), n) or cmp == rot180(reflex(ori, n), n) or cmp == rot270(reflex(ori, n), n):
    fout.write('5\n')
elif cmp == ori:
    fout.write('6\n')
else:
    fout.write('7\n')
fout.close()
