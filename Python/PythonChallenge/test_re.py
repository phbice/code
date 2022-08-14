'''
One small letter, surrounded by EXACTLY three
big bodyguards on each of its sides.
2018-8-12 17:20:18
'''

from collections import deque
import re

file = open('data_str2.txt', 'r')
for line in file:
	match = re.search(r'[^A-Z]([A-Z]{3}[a-z][A-Z]{3})[^A-Z]', line)
	if match:
		print(match.group(1))
		break
file.close()
