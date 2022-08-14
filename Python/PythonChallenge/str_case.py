'''
One small letter, surrounded by EXACTLY three
big bodyguards on each of its sides.
2018-8-12 17:20:18
'''

from collections import deque

def matchCase(list, caseFlag):
	"""check the case of each letter of list
	according to caseFlag
	caseFlag is a string made of '0' and '1'
	'0' represent lowercase or empty string ''
	'1' represent UPPERCASE
	"""
	
	flag = {'0': False, '1': True}
	for i in range(9):
		if list[i].isupper() != flag[caseFlag[i]]:
			return False
	return True

file = open('data_str2.txt', 'r')
queue = deque('a' + file.read(7), 9)

c = 'a'
while c != '':
	c = file.read(1)
	if c != '\n':
		queue.append(c)
	if matchCase(queue, '011101110'):
		print(queue)
