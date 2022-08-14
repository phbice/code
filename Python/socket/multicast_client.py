import socket
import time

ANY = '0.0.0.0'
MCAST_ADDR = '224.168.102.5'
MCAST_PORT = 7343

def gethostip():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(('8.8.8.8', 53))
        ip = s.getsockname()[0]
    finally:
        s.close()
    return ip

LOCAL_IP = gethostip()

recv_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM,
    socket.IPPROTO_UDP)
recv_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)
recv_sock.bind((ANY, MCAST_PORT))
recv_sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 2)
status = recv_sock.setsockopt(socket.IPPROTO_IP,
    socket.IP_ADD_MEMBERSHIP,
    socket.inet_aton(MCAST_ADDR) + socket.inet_aton(LOCAL_IP))

recv_sock.setblocking(0)
while True:
    try:
        data, addr = recv_sock.recvfrom(1024)
    except socket.error as e:
        pass
    else:
        print("We got data!")
        print("FROM:", addr)
        print("DATA:", data)