'''
2018-8-17 15:17
'''

from urllib import request
from http import cookiejar
import re

#cookie:
cookie = cookiejar.CookieJar()
handler = request.HTTPCookieProcessor(cookie)
opener = request.build_opener(handler)
values = []

url = 'http://www.pythonchallenge.com\
/pc/def/linkedlist.php?busynothing='
nextNum = '12345'
compiledPattern = re.compile(r'and the next busynothing is ([0-9]+)$')

while True:
	f = request.urlopen(url + nextNum)
	opener.open(url + nextNum)
	values += [item.value for item in cookie]
	data = f.read().decode('utf-8')
	match = compiledPattern.search(data)

	if match:
		nextNum = match.group(1)
	else:
		break

print(values)