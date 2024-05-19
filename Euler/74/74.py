fac = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]

def calc(i): 
    s = 0
    while i != 0:
        s += fac[i % 10]
        i = i // 10
    return s

ans = 0
lim = 1000001

for b in range(1, lim):
    l = []
    c = b
    done = False
    while not done:
        l.append(c)
        c = calc(c)
        if c in l:
            if len(l) == 60:
                ans += 1
            done = True
        if len(l) > 60:
            break
    #print(str(b) + " " + str(len(l)))
    #print(l)

print(ans)