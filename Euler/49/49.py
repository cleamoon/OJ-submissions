lim = 10000

num = [True for _ in range(lim)]

for i in range(4, lim, 2):
    num[i] = False

for i in range(3, lim, 2):
    if num[i]:
        for j in range(i * i, lim, 2 * i):
            num[j] = False

dic = {}

for i in range(1001, lim, 2):
    if num[i]:
        k = ''.join(sorted(list(str(i))))
        if k in dic:
            dic[k].append(i)
        else:
            dic[k] = [i]

for k in dic:
    l = len(dic[k])
    if l >= 3:
        dic[k].sort()
        for a in range(0, l-2):
            for b in range(a + 1, l-1):
                for c in range(b + 1, l):
                    if dic[k][c] - dic[k][b] == dic[k][b] - dic[k][a]:
                        print(str(dic[k][a]) + str(dic[k][b]) + str(dic[k][c]))

