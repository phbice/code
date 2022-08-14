'''
find a leap year, January 26 is Monday
2018-8-15 15:58
'''
from calendar import isleap
from datetime import date

for i in range(1016, 1997, 4):
	if isleap(i) and date(i, 1, 26).weekday() == 0:
		print(i)
