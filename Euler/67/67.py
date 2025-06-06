res = []

with open("triangle.txt") as f:
    line = f.readline()
    while line:
        ln = list(int(x) for x in line.split())
        if res == []:
            res.append(ln[0])
        else:
            tmp = res
            res = []
            res.append(ln[0] + tmp[0])
            for i in range(1, len(ln) - 1):
                res.append(max(tmp[i], tmp[i - 1]) + ln[i])
            res.append(ln[-1] + tmp[-1])
        line = f.readline()

print(max(res))