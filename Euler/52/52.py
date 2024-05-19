for i in range(1, 1000000):
    s = set(list(str(i)))
    done = True
    for k in range(2, 7):
        if set(list(str(i*k))) != s:
            done = False
            break
    if done:
        print(i)
        break