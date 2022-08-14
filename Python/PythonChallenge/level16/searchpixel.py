'''
search pixel
2018-8-15 16:33
'''

from PIL import Image

img = Image.open('mozart.gif')

for i in range(img.size[1]):
	line = [img.getpixel((j, i)) for j in range(img.size[0])]
	idx = line.index(195)
	line = line[idx-1:] + line[:idx-1]
	for j in range(img.size[0]):
		img.putpixel((j, i), line[j])
img.save('mozart2.gif')
img.close()
'''
imgdata = list(img.getdata())
rawpalette = img.getpalette()
palette = []
for i in range(0, len(rawpalette), 3):
	palette.append(tuple(rawpalette[i : i+3]))

L = []
pattern = [(255, 0, 255), (255, 0, 255), (255, 0, 255),\
(255, 0, 255), (255, 0, 255)]
for i in range(len(imgdata)-4):
	if [palette[imgdata[i + j]] for j in range(5)] == pattern:
		L.append(i)

result = open('result.txt', 'w')
for point in L:
	x = point%img.width
	y = point//img.width
	left = imgdata[point-1]
	right = imgdata[point+5]
	result.write('%d %d %d, (%d, %d)\n'\
	%(left, right, left - right, x, y))

img.close()
result.close()
'''