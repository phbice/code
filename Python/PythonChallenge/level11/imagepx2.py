from PIL import Image

img = Image.open('cave.jpg')
width = img.size[0]
height = img.size[1]
evenImg = Image.new('RGB', (width//2, height))
oddImg = Image.new('RGB', (width//2, height))

pixelData = list(img.getdata())
evenPixel = []
oddPixel = []

i = 0
for pixel in pixelData:
	if (i % width + i // width) % 2 == 0:
		evenPixel.append(pixel)
	else:
		oddPixel.append(pixel)
	i = i + 1
evenImg.putdata(evenPixel)
oddImg.putdata(oddPixel)
evenImg.save('cave_even.png')
oddImg.save('cave_odd.png')

img.close()
evenImg.close()
oddImg.close()