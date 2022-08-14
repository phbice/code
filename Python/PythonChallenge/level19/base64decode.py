'''
base64
2018-8-17 20:21
'''
import base64
src = open('indian.txt', 'r')
bindata = open('indian.wav', 'wb')
bindata.write(base64.b64decode(src.read()))