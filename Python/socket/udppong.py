'''udppong.py'''
import time
import random
import struct
from socket import *

serverPort = 12345
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
while True:
    recvMessage, clientAddress = serverSocket.recvfrom(2048)
    if len(recvMessage) != 12:
        continue
    recvMessage = struct.unpack('<4s8s',recvMessage)
    if recvMessage[0] == b'PING':
        respondMessage = struct.pack('<4s8s', b'PONG', recvMessage[1])
        serverSocket.sendto(respondMessage, clientAddress)