ans = 0

for b in range(1, 10):
    for p in range(1, 1000):
        if p == len(list(str(b**p))):
            ans += 1

print(ans)