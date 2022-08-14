import re

pattern = re.compile(r'^Next nothing is ([0-9]+)$')
nextNum = '90052'
L = []
while True:
	L.append(nextNum)
	file = open(nextNum + '.txt', 'r')
	content = file.read()
	file.close()
	# get next number
	match = pattern.match(content)
	if not match:
		print('number = %s\n%s' % (nextNum, content))
		inputNum = input('Input next number, "q" to quit: ')
		if inputNum == 'q': break
		nextNum = inputNum
	else:
		nextNum = match.group(1)

file = open('follow.txt', 'w')
for num in L:
	file.write(num + '\n')
file.close()