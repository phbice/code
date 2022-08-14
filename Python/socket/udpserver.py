'''UDP server.py'''

from socket import *

serverPort = 12345
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print('The server is ready to receive.')
while True:
    try:
        message, clientAddress = serverSocket.recvfrom(2048)
        print('Received a connection from: %s:%s' %clientAddress)
        print('The client says: "%s"' % message.decode())
    except ConnectionResetError:
        pass
    if message in (b'HELLO', b'BROADCAST'):
        serverSocket.sendto(b'WELCOME', clientAddress)
    elif message == b'CLOSE':
        print('Server is closing...')
        break
