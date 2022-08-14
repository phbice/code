file = open('data.txt', 'r')
c = file.read(1)
while c != '':
    if ord('a') <= ord(c) and ord(c) <= ord('z'):
	    print(c, end = '') #print 以end指定的符号结尾，默认为换行
    c = file.read(1)
file.close()