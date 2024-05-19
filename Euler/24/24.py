import itertools
alll = list(itertools.permutations([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))
alll = sorted(alll)

print(int(''.join(str(i) for i in alll[1000000-1])))