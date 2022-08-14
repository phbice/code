'''
UDP Broadcast
'''
import sys
import socket

class broadcast_socket:
    def __init__(self, addr, port, broadcast_flag=True):
        self.addr = addr
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        if broadcast_flag:
            self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        else:
            self.sock.bind(('', self.port))

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_value, exc_traceback):
        self.sock.close()

    def broadcast(self, data):
        self.sock.sendto(data, (self.addr, self.port))

    def recive(self):
        return self.sock.recvfrom(4096)

    def close(self):
        self.sock.close()

def main():
    bc_addr = '10.131.255.255' # bc = broadcast
    bc_port = 12346
    try:
        arg = sys.argv[1]
    except IndexError:
        with broadcast_socket(bc_addr, bc_port) as bs:
            bs.broadcast(f'BROADCAST {socket.gethostname()}'.encode())
    else:
        if arg == '-r':
            with broadcast_socket(bc_addr, bc_port, False) as bs:
                while True:
                    data, client_addr = bs.recive()
                    if data == b'CLOSE':
                        break
                    else:
                        print('Recieved from: %s:%s' % client_addr)
                        print(f'The client says: {data.decode()}')
        elif arg == '-c':
            with broadcast_socket(bc_addr, bc_port) as bs:
                bs.broadcast(b'CLOSE')

if __name__ == '__main__':
    main()
