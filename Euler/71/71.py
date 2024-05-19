lim = 1000000
mdiff = 10.0
ma = 0
mb = 0
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

for b in range(8, lim):
    ap = 3 * b // 7
    for a in range(ap, 0, -1):
        if gcd(b, a) == 1:
            m = float(3 * b - 7 * a) / b
            if m < mdiff:
                mdiff = m
                ma = a
                mb = b
            break
    
print(ma)
