import math

ans = 0

for n in range(1, 101):
    for r in range(1, n):
        s = math.factorial(n) // math.factorial(r) // math.factorial(n-r) 
        if s > 1000000:
            ans += 1

print(ans)