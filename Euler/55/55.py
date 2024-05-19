ans = 0

def revn(n):
    l = list(str(n))
    l.reverse()
    return int(''.join(l))

def ispalind(n):
    l = list(str(n))
    t = l.copy()
    t.reverse()
    return l == t

for i in range(1, 10001):
    t = 1
    isp = False
    s = i + revn(i)
    while t < 50:
        if ispalind(s):
            isp = True
            break
        else:
            s = s + revn(s)
        t += 1
    if not isp:
        ans += 1

print(ans)