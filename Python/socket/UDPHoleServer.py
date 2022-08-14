'''UDP hole'''

from socket import *
import struct

def EncodeAddr(AddrTuple):
    return struct.pack('<H', AddrTuple[1]) + AddrTuple[0].encode()

ServerPort = 30001

ServerSocket = socket(AF_INET, SOCK_DGRAM)
ServerSocket.bind(('', ServerPort))

Peer1Addr = ServerSocket.recvfrom(2048)[1]
Peer2Addr = ServerSocket.recvfrom(2048)[1]

ServerSocket.sendto(EncodeAddr(Peer1Addr), Peer2Addr)
ServerSocket.sendto(EncodeAddr(Peer2Addr), Peer1Addr)