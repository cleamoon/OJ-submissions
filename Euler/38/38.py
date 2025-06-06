mpd = 0

cmp = set(list(str(123456789)))

for i in range(9999, 1, -1):
    t = []
    for j in range(1, 6):
        t += (list(str(i * j)))
        if len(t) > 9:
            break
        if len(t) == 9:
            if set(t) == cmp:
                pd = int(''.join(t))
                if pd > mpd:
                    mpd = pd

print(mpd)