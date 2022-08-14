'''TCP server'''
from socket import *
serverPort = 12345
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)
print('The server is ready to receive.')
while True:
    connectionSocket, addr = serverSocket.accept()
    print('Received a connection: %s:%s' %addr)
    receive = connectionSocket.recv(2048)
    print('Client says:"%s"' %receive.decode())
    if receive == b'HELLO':
        connectionSocket.send(b'WELCOME')
        connectionSocket.close()