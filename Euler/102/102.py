def cross(a, b, c, d):
    return (a*d - b*c > 0)

with open("triangles.txt", "r") as f:
    ret = 0
    lines = f.readlines()
    for line in lines:
        elems = line.split(',')
        x = [float(elems[0]), float(elems[2]), float(elems[4])]
        y = [float(elems[1]), float(elems[3]), float(elems[5])]
        c = [cross(x[0], y[0], x[1], y[1]), cross(x[1], y[1], x[2], y[2]), cross(x[2], y[2], x[0], y[0])]
        if (c[0] and c[1] and c[2]):
            ret += 1
        if ((not c[0]) and (not c[1]) and (not c[2])):
            ret += 1
    
    print(ret)
        