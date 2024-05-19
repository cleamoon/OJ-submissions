import math

def gcd(a, b):
    if a < 0:
        return gcd(-a, b)
    if b < 0:
        return gcd(a, -b)
    if a < b:
        return gcd(b, a)
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def calc(k):
    i = 0
    a = [1]
    b = [0]
    c = [1]
    m = []
    while True:
        m.append(math.floor((a[i] * math.sqrt(k) + b[i])/c[i]))
        a.append(a[i] * c[i])
        b.append(c[i] * (m[i] * c[i] - b[i]))
        c.append(a[i] * a[i] * k - (b[i] - m[i] * c[i]) ** 2)
        i += 1
        gab = gcd(a[i], b[i])
        g = gcd(gab, c[i])
        #print("g: " + str(g))
        a[i] //= g
        b[i] //= g
        c[i] //= g
        #print("a: " + str(a[i]))
        #print("b: " + str(b[i]))
        #print("c: " + str(c[i]))
        #print("m: " + str(m[i - 1]))
        period = 0
        for j in range(i-1, 1, -1):
            if m[j-1] == m[i-1] and a[j] == a[i] and b[j] == b[i] and c[j] == c[i]:
                period = i - j
        if period > 0:
            #print(period)
            return period
            break

oddperiod = 0

for i in range(2, 10000 + 1):
    s = round(math.sqrt(i))
    if s * s == i:
        continue
    if calc(i) % 2 == 1:
        oddperiod += 1

print(oddperiod)