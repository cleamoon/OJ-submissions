t = 0

def calc(n):
    p = 0
    for j in range(1, n):
        if n % j == 0:
            p += j
    q = 0
    for j in range(1, p):
        if p % j == 0:
            q += j
    if n == q and n != p:
        return n
    else:
        return 0


for i in range(1, 10001):
    t += calc(i)    

print (t)
