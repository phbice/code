'''UDP ping'''
import time
import sys
import struct
from socket import *

if len(sys.argv) != 2:
    print('usage: %s host_name' %sys.argv[0])
    print('for example: %s 198.13.43.92' %sys.argv[0])
    sys.exit()

serverName = sys.argv[1]
serverPort = 12345
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(1.000)

for i in range(10):
    sendtime = time.time()
    bSendtime = struct.pack('<d', sendtime)
    sendMessage = struct.pack('<4s8s', b'PING', bSendtime)

    clientSocket.sendto(sendMessage, (serverName, serverPort))
    try:
        respondMessage, addr = clientSocket.recvfrom(2048)
    except timeout:
        print('Request timeout.')
    else:
        respond = struct.unpack('<4s8s', respondMessage)
        if respond == (b'PONG', bSendtime):
            print('RTT:', time.time()-sendtime)

clientSocket.close()