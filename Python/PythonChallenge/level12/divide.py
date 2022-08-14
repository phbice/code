srcfile = open('evil2.gfx', 'rb')
srccontent = srcfile.read()
dst = [open(str(i) + '.jpg', 'wb') for i in range(5)]
i = 0
for byte in srccontent:
	dst[i%5].write(bytes([byte]))
	i = i + 1
srcfile.close()
for file in dst:
	file.close()