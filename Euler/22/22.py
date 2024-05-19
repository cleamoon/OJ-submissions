wl = []
with open("names.txt") as f:
    wl = list(x.replace('"', '') for x in f.read().split(','))
wl.sort()
s = 0
for i in range(0, len(wl)):
    ws = 0
    for c in wl[i]:
        if c.isalpha():
            ws += ord(c) - ord('A') + 1
    s += ws * (i + 1)
print(s)