pro = 1
tar = 1
cur = 1
pos = 1
i = 1

while i < 8 :
    lcur = list(str(cur))
    if len(lcur) > tar - pos:
        pro *= int(lcur[tar-pos])
        i += 1
        tar *= 10
    pos += len(lcur)
    cur += 1

print(pro)
