s = 0

for i in range(3, 1001):
    s += i * ((i - 1) // 2) * 2

print(s)