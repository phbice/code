import qrcode
#data = input('Input: ')
qr = qrcode.QRCode(border=1)
qr.add_data('Hello, world!')
matrix = qr.get_matrix()
for line in matrix:
    print(*('█' if cell else '　' for cell in line), sep='')
input()
