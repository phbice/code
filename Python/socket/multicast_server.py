import socket
import time

ANY = '0.0.0.0'
SEND_PORT= 7342
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
print(LOCAL_IP)

send_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM,
    socket.IPPROTO_UDP)
send_sock.bind((ANY, SEND_PORT))
status = send_sock.setsockopt(socket.IPPROTO_IP,
    socket.IP_MULTICAST_IF, socket.inet_aton(LOCAL_IP))
send_sock.setsockopt(socket.IPPROTO_IP,
    socket.IP_MULTICAST_TTL, 2)

while True:
    time.sleep(3)
    send_sock.sendto(b'Hello World', (MCAST_ADDR, MCAST_PORT))