"""
ID: yj1
LANG: PYTHON3
TASK: friday
"""
fin = open ('friday.in', 'r')
fout = open ('friday.out', 'w')

n = int(fin.readline())
start = 1900
day = 1
month = 1
week = 1
stop = start + n
months = []
tdays = 365

nWeek = [0, 0, 0, 0, 0, 0, 0]

for i in range(start, stop):
    day = 1
    month = 1
    if (i % 400 == 0) or ( (i % 100 != 0) and (i % 4 == 0)):
        months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        tdays = 366
    else:
        months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        tdays = 365
    for j in range(tdays):
        if day == 13:
            nWeek[week-1] += 1
        '''print('day ' + str(day))
        print('week ' + str(week))
        print('month ' + str(month) + '\n')'''
        day += 1
        week += 1
        if day > months[month-1]:
            day = 1
            month += 1
        if week > 7:
            week = 1

fout.write(str(' '.join(str(number) for number in nWeek[-2:])) + ' ')
fout.write(str(' '.join(str(number) for number in nWeek[:-2])) + '\n')
fout.close()

