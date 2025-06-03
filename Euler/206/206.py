for i in range(1010101010, 1389026630, 10):
    s = str(i * i)
    find = True
    for k in range(1, 10):
        if s[(k - 1) * 2] != str(k):
            find = False
            break
    if find:
        print(i)
        break