'''
look-and-say sequence
'''
def nextnum(a):
	i = 0
	result = ''
	timesList = [[a[0],0]]
	for digital in a:
		if digital == timesList[-1][0]:
			i = i + 1
		else:
			timesList[-1][1] = i
			timesList.append([digital,0])
			i = 1
	timesList[-1][1] = i
	for op in timesList:
		result = result + str(op[1]) + op[0]
	return result

a = '1'
for i in range(0, 30):
	a = nextnum(a)
print(len(a))