"""
ID: yj1
LANG: PYTHON3
TASK: namenum
"""
fin = open ('namenum.in', 'r')
fout = open ('namenum.out', 'w')
fdata = open ('dict.txt', 'r')

def trans(word):
    dic = {'A':'2', 'B':'2', 'C':'2', 'D':'3', 'E':'3', 'F':'3', 'G':'4', 'H':'4', 'I':'4', 'J':'5', 'K':'5', 'L':'5', 'M':'6', 'N':'6', 'O':'6', 'P':'7', 'R':'7', 'S':'7', 'T':'8', 'U':'8', 'V':'8', 'W':'9', 'X':'9', 'Y':'9', 'Q':'0', 'Z':'0'}
    res = []
    for i in word:
        res.append(dic[i])
    return res

n = fin.readline().rstrip()
found = False

for s in fdata:
    c = ''.join(trans(str(s).rstrip()))
    if c == n:
        found = True
        fout.write(s)

if not found:
    fout.write('NONE\n')

fout.close()

