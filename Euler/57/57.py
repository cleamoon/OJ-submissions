ans = 0

num = 3
den = 2

for i in range(1, 1000):
    tmp = num + den
    num = tmp + den
    den = tmp
    if len(str(num)) > len(str(den)):
        ans += 1

print(ans)
