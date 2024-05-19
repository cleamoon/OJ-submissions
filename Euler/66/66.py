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

def calc(D):
    i = 0
    a = [1]
    b = [0]
    c = [1]
    m = []
    h = [0, 1]
    k = [1, 0]
    while True:
        m.append(math.floor((a[i] * math.sqrt(D) + b[i])/c[i]))
        a.append(a[i] * c[i])
        b.append(c[i] * (m[i] * c[i] - b[i]))
        c.append(a[i] * a[i] * D - (b[i] - m[i] * c[i]) ** 2)
        i += 1
        gab = gcd(a[i], b[i])
        g = gcd(gab, c[i])
        a[i] //= g
        b[i] //= g
        c[i] //= g
        h.append(m[i-1] * h[i] + h[i-1])
        k.append(m[i-1] * k[i] + k[i-1])
        if h[i+1] * h[i+1] - D * k[i+1] * k[i+1] == 1:
            #print("x: " + str(h[i+1]))
            #print("D: " + str(D))
            #print("y: " + str(k[i+1]))
            return h[i+1]

maxx = 0
maxD = 0

for D in range(2, 1000 + 1): 
    sr = round(math.sqrt(D))
    if sr * sr == D:
        continue
    x = calc(D)
    if x > maxx:
        maxx = x
        maxD = D

print(maxD)
