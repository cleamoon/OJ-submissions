import sys,math
eps=1e-12
for i in sys.stdin:
    ab = i.split()
    n = int(ab[0])
    k = int(ab[1])
if (n<=math.pow(2,k)):
	print("Your wish is granted!")
else:
	print("You will become a flying monkey!")
