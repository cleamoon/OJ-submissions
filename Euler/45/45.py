ltn = []
lpn = []

for i in range(1, 1000000):
    t = 143 + i
    p = 165 + i
    ltn.append(t * (2 * t - 1))
    lpn.append(p * (3 * p - 1) // 2)

def bst(n, b = 0, e = len(ltn)):
    if b >= e:
        if ltn[b] == n:
            return True
        else:
            return False
    else:
        m = (b + e)//2
        if n > ltn[m]:
            return bst(n, m+1, e)
        elif n < ltn[m]:
            return bst(n, b, m)
        else:
            return True

for p in lpn:
    if (bst(p)):
        print(p)
        break
