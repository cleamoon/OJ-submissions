wl = []
with open("words.txt") as f:
    wl = f.read().replace('"', '').split(",")

lim = 1000000

num = [False for _ in range(lim)]

for i in range(1, lim):
    t = i * (i + 1) // 2
    if t >= lim:
        break
    num[t] = True

ans = 0

for w in wl:
    s = 0
    for c in w:
        s += ord(c) - ord('A') + 1
    if num[s]:
        ans += 1

print(ans)