import itertools

nl = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

sum = 0;

for pt in itertools.permutations(nl):
    p = list(pt)
    if p[0] == '0':
        continue
    s = [0 for _ in range(7)]
    for i in range(1, 8):
        s[i - 1] = int(''.join(p[i:i+3]))
    if (s[0]%2) + (s[1]%3) + (s[2]%5) + (s[3]%7) + (s[4]%11) + (s[5]%13) + (s[6]%17) == 0:
        sum += int(''.join(p))

print(sum)
