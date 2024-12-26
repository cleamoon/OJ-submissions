ans = 1.0

for a in range(1, 10):
    for b in range(1, 10):
        for c in range(1, 10):
            if (10*a + b) * c == (10*b + c) * a and (10*a + b) != (10*b + c):
                # print(10 * a + b)
                # print(10 * b + c)
                ans /= a/c
            if (10*a + b) * c == (10*c + b) * a and (10*a + b) != (10*c + b):
                # print(10 * a + b)
                # print(10 * c + b)
                ans /= c/a
            if (10*a + b) * c == (10*a + c) * b and (10*a + b) != (10*a + c):
                # print(10*a + b)
                # print(10*a + c)
                ans /= c/b

print(ans)