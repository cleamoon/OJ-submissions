trg = 100

num = 1
den = 0

for i in range(trg, 0, -1):
    tmp = num
    num = den
    den = tmp
    if i == 0:
        num += 2 * den
    elif i % 3 == 0:
        num += (i // 3 * 2) * den
    else:
        num += den

num += den

print(sum(list(int(x) for x in list(str(num)))))
        
