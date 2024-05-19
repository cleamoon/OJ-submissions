"""
ID: yj1
LANG: PYTHON3
TASK: palsquare
"""
fin = open ('palsquare.in', 'r')
fout = open ('palsquare.out', 'w')
b = int(fin.readline())
def trans(n, b):
    res = []
    while n != 0:
        i = n%b
        if i<10:
            res.append(str(n%b))
        elif i==10:
            res.append("A")
        elif i==11:
            res.append("B")
        elif i==12:
            res.append("C")
        elif i==13:
            res.append("D")
        elif i==14:
            res.append("E")
        elif i==15:
            res.append("F")
        elif i==16:
            res.append("G")
        elif i==17:
            res.append("H")
        elif i==18:
            res.append("I")
        elif i==19:
            res.append("J")
        elif i==20:
            res.append("K")        
        n = n//b
    return list(reversed(res))

for i in range(1, 301):
    t = trans(i*i, b)
    if t == list(reversed(t)):
        fout.write(''.join(trans(i,b)) + ' ' + ''.join(t) + '\n')

fout.close()

