'''
hex string to file
2018-8-17 16:37
'''
import difflib
import re

src = open('delta.txt', 'r')
linesl = []
linesr = []
for line in src:
	if line[0:53] != ' ' * 53:
		linesl.append(line[0:53])
	linesr.append(line[56:109].strip())

diff = list(difflib.Differ().compare(linesl, linesr))

dst = [open('dst' + str(i) + '.png', 'wb') for i in range(3)]
for item in diff:
#    print(bytes(item, encoding='utf-8'))
    if item[0:2] == '- ':
        dst[0].write(bytes.fromhex(item[2:]))
    elif item[0:2] == '+ ':
        dst[1].write(bytes.fromhex(item[2:]))
    else:
        dst[2].write(bytes.fromhex(item[2:]))

src.close()
for file in dst: file.close()
