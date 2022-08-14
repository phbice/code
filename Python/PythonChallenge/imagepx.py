'''
deal with image at a pixel level
2018-8-13 18:11
'''
from PIL import Image
#import pdb
#pdb.set_trace()
img = Image.open('oxygen.png')
px = img.load()
grayLevelList = bytearray()
grayLevelList.append(px[0,45][0])
i = 0
while px[i,45][0] == px[i,45][1] == px[i,45][2]:
	grayLevelList.append(px[i,45][0])
	i = i + 7
print(grayLevelList.decode())
img.close()