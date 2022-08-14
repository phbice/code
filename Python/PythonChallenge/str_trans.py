chipertext = "http://www.pythonchallenge.com/pc/def/map.html"
plaintext = ''

'''
for c in chipertext:
    if ord('a') <= ord(c) and ord(c) <= ord('z') :
	    c = chr( (ord(c)-ord('a') + 2) % 26 + ord('a'))
    plaintext = plaintext + c
print(plaintext)
'''
translateTable = chipertext.maketrans("abcdefghijklmnopqrstuvwxyz",\
                                      "cdefghijklmnopqrstuvwxyzab")
plaintext = chipertext.translate(translateTable)
print(plaintext)