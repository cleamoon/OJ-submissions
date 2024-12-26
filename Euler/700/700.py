# import math

# cm = 4503599627370517

# vis = set()

# sum = 0

# c = 0

# while True:
#     c += 1504170715041707
#     c %= 4503599627370517
#     if c < cm:
#         sum += c
#         cm = c
#     if c in vis:
#         break
#     vis.add(c)
#     print(cm)
#     print(sum)

circ = 4503599627370517
step = 1504170715041707
eulc = 1504170715041707
sum = 1504170715041707

while eulc > 1:
    back = circ - circ // step * step
    eulc -= back
    sum += eulc
    circ = step
    step = eulc

print(sum)