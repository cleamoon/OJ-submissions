lim = 10000001

num = [0 for _ in range(lim)]

def calc(n): 
    if num[n] != 0:
        return num[n]
    else:
        s = 0
        for k in list(str(n)):
            s += int(k) * int(k)
        if s == 1:
            num[n] = 1
            return 1
        elif s == 89:
            num[n] = 89
            return 89
        else:
            num[n] = calc(s)
            return num[n]

ans = 0

for i in range(1, lim): 
    calc(i)
    if num[i] == 89:
        ans += 1
    if num[i] != 89 and num[i] != 1:
        print(i)
        print(num[i])

print(ans)