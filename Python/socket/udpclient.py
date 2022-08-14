'''UDP client'''
import time
from socket import *

#serverName = '198.13.43.92'
serverName = '127.0.0.1'
serverPort = 12345
message = 'HELLO'

clientSocket = socket(AF_INET, SOCK_DGRAM)
#clientSocket.bind(('', 30000))
clientSocket.sendto(message.encode('utf-8'), (serverName, serverPort))
respond, serverAddress = clientSocket.recvfrom(2048)
print(respond.decode())

time.sleep(5)
clientSocket.sendto(b'CLOSE', (serverName, serverPort))

clientSocket.close()
