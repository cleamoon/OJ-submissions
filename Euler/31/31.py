
cl = [1, 2, 5, 10, 20, 50, 100, 200]

def calc(m, n):
    if m < 0 or n < 0:
        return 0
    if m == 0:
        return 1
    return calc(m - cl[n], n) + calc(m, n - 1)

print(calc(200, len(cl) - 1))
