s = input()
li = s.split()

res = []
curr = True

while len(li) != 0:
    if curr:
        li.append(li[0])
    else:
        res.append(li[0])

    li = li[1:]
    curr = not curr

print(" ".join(res))
