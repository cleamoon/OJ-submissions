li = []

while True:
    e = input()
    if e == "#":
        break
    li.append(e)

while True:
    e = input()
    if e == "#":
        break
    if e in li:
        print(e + " found")
    else:
        print(e + " not found")
