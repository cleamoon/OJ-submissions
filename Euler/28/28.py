s = 1

for i in range(3, 1002, 2):
    s += i * i * 4 - (1 + 2 + 3) * (i - 1)

print(s)