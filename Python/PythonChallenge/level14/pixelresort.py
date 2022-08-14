'''
resort the pixel
2018-8-15 15:00
'''
from PIL import Image
img = Image.open('wire.png')
imgdata = img.getdata()
resorted = Image.new(img.mode, (100, 100))

srccoord = 0
dstcoord = [0, 0]
for i in range(100, 0, -2):
	for j in range(i):
		resorted.putpixel(tuple(dstcoord), imgdata[srccoord])
		dstcoord[0] = dstcoord[0] + 1
		srccoord  = srccoord + 1
	dstcoord[0] = dstcoord[0] - 1
	dstcoord[1] = dstcoord[1] + 1
	for j in range(i-1):
		resorted.putpixel(tuple(dstcoord), imgdata[srccoord])
		dstcoord[1] = dstcoord[1] + 1
		srccoord = srccoord + 1
	dstcoord[0] = dstcoord[0] - 1
	dstcoord[1] = dstcoord[1] - 1
	for j in range(i-1):
		resorted.putpixel(tuple(dstcoord), imgdata[srccoord])
		dstcoord[0] = dstcoord[0] - 1
		srccoord = srccoord + 1
	dstcoord[0] = dstcoord[0] + 1
	dstcoord[1] = dstcoord[1] - 1
	for j in range(i-2):
		resorted.putpixel(tuple(dstcoord), imgdata[srccoord])
		dstcoord[1] = dstcoord[1] - 1
		srccoord = srccoord + 1
	dstcoord[0] = dstcoord[0] + 1
	dstcoord[1] = dstcoord[1] + 1

resorted.save('result.png')	
img.close()
resorted.close()
