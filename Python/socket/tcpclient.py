'''TCP client'''
import time
from socket import *
#serverName = '198.13.43.92'
serverName = '127.0.0.1'
serverPort = 12345
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
clientSocket.send(b'HELLO')
respond = clientSocket.recv(2048).decode('utf-8')
print(respond)

clientSocket.close()