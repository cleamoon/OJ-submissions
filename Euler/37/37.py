import itertools 

lim = 1000000
num = [True for _ in range(lim)]

num[1] = False

for i in range(4, lim, 2):
    num[i] = False

for i in range(3, lim, 2):
    if num[i]:
        for j in range(i*i, lim, 2*i):
            num[j] = False

ans = 0

for i in range(11, 1000000, 2):
    if num[i]:
        isccl = True
        li = list(str(i))
        for n in range(1, len(li)):
            t = int(''.join(li[:n]))
            if not num[t]:
                isccl = False
                break
        if not isccl:
            continue
        for n in range(1, len(li)):
            t = int(''.join(li[n:]))
            if not num[t]:
                isccl = False
                break
        if isccl:
            ans += i

print(ans)