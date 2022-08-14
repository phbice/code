'''
use urllib
2018-8-13 10:30
'''

from urllib import request
import re

url = 'http://www.pythonchallenge.com\
/pc/def/linkedlist.php?nothing='
lastNum = '12345'
f = request.urlopen(url + lastNum)
data = f.read().decode('utf-8')
compiledPattern = re.compile(r'^and the next nothing is ([0-9]+)$')
match = compiledPattern.search(data)
while True:
	if not match:
		print('nothing=' + lastNum + '\n' + data)
		tempLastNum = input('Input the next number, "q" to quit: ')
		if tempLastNum == 'q': break
		lastNum = tempLastNum
		print()
	else:
		lastNum = match.group(1)
	f = request.urlopen(url + lastNum)
	data = f.read().decode('utf-8')
	match = compiledPattern.search(data)
print(lastNum)