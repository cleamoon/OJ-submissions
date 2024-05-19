import sys
#b = int(input())
#p = int(input())
#m = int(input())
while True:
	s = input()
	if s == "0":
		sys.exit()

	b, p, m = s.split()
	b = int(b)

	pp = 0
	mm = 0

	i = 0
	while len(p)>i:
		pp = pp*b + int(p[i])
		i = i+1

	i = 0
	while len(m)>i:
		mm = mm*b + int(m[i])
		i = i+1

	if mm != 0:
		r = pp%mm
	else:
		r = pp

	an = []

#print(pp)
#print(mm)
#print(r)

	while r!=0:
		an.append(r%b)
		r = r//b;

	an.reverse()
	if len(an) < 1:
		an = [0]

	for i in an:
		print (i, end='')

	print ()

