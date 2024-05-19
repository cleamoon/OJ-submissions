"""
ID: yj1
LANG: PYTHON3
TASK: beads
"""
fin = open ('beads.in', 'r')
fout = open ('beads.out', 'w')
n = int(fin.readline())
tmp = list(fin.readline().rstrip('\n'))
neck = tmp + tmp 

maximum = -1

for i in range(len(neck)):
    left = 0
    right = 0
    for j in reversed(range(i+1)):
        if neck[j] == 'w':
            left += 1
            continue
        else:
            if neck[j] == 'b':
                for k in reversed(range(j+1)):
                    if neck[k] != 'r':
                        left += 1
                    else:
                        break
            if neck[j] == 'r':
                for k in reversed(range(j+1)):
                    if neck[k] != 'b':
                        left += 1
                    else:
                        break
        break
    print('left: ' + str(right))

    for j in range(i+1, len(neck)):
        if neck[j] == 'w':
            left += 1
            continue
        else:
            if neck[j] == 'b':
                for k in range(j, len(neck)):
                    if neck[k] != 'r':
                        right += 1
                    else:
                        break
            if neck[j] == 'r':
                for k in range(j, len(neck)):
                    if neck[k] != 'b':
                        right += 1
                    else:
                        break
        break
    print('right: ' + str(right))

    if left + right > maximum:
        maximum = left + right
    print(str(maximum))

if maximum > n:
    maximum = n

fout.write (str(maximum) + '\n')
fout.close()

