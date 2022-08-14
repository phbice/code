'''UDP hole'''

from socket import *
import struct

def DecodeAddr(AddrBytes):
    return (respond[2:].decode(), struct.unpack('<H', respond[:2]))

ServerName = '206.189.222.234'
ServerPort = 30001
ClientPort = 30000

ClientSocket = socket(AF_INET, SOCK_DGRAM)
ClientSocket.bind(('', ClientPort))

# Get host IP
ClientSocket.connect((ServerName, ServerPort))
ClientName = ClientSocket.getsockname()[0]

print('Sending...', flush=True)
ClientSocket.sendto(ClientName.encode(), (ServerName, ServerPort))
print('Sent', flush=True)
respond = ClientSocket.recvfrom(2048)[0]
print('Received', flush=True)
PeerAddr = DecodeAddr(respond)

# UDP hole
ClientSocket.settimeout(1.00)
while True:
    ClientSocket.sendto('HELLO'.encode(), PeerAddr)
    try:
        respond, address = ClientSocket.recvfrom(2048)
    except timeout:
        continue
    if address == PeerAddr:
        if respond.decode() == 'HELLO':
            ClientSocket.sendto('OK'.encode(), PeerAddr)
        break

ClientSocket.settimeout(None)

print('UDP holing succeeded\n')
choice = input('[1] Send\n [2] Receive\n>>>')
if choice == '1':
    message = input('Say something... >>>')
    ClientSocket.sendto(message.encode(), PeerAddr)
else:
    respond = ClientSocket.recvfrom(2048)[0]
    print(respond.decode())

ClientSocket.close()