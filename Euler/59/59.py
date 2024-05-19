with open("cipher.txt") as f:
    cl = [int(x) for x in f.read().split(',')]

dl = list(range(len(cl)))

for i in range(26):
    for j in range(26):
        for k in range(26):
            for n in range(len(cl)):
                a = i + ord('a')
                b = j + ord('b')
                c = k + ord('c')
                if n % 3 == 0:
                    dl[n] = cl[n] ^ a
                elif n % 3 == 1:
                    dl[n] = cl[n] ^ b
                else:
                    dl[n] = cl[n] ^ c
            s = str(''.join(chr(n) for n in dl))
            common = ['the', 'of', 'to', 'is', 'that', 'for', 'on']
            found = True
            for co in common:
                if co not in s:
                    found = False
                    break
            if found:
                print(s)
                sum = 0
                for d in dl:
                    sum += d
                print(sum)
                exit()
