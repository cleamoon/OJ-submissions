e = 100

ans = [0 for _ in range(e + 1)]

ans[0] = 1

for i in range (1, e):
    for j in range(i, e + 1):
        ans[j] += ans[j - i]

print(ans[e])