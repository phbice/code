import socket
from http.server import *

def mime(filename):
    '''根据文件名返回MIME类型'''
    mimedic = {
        'html': 'text/html',
        'htm' : 'text/html',
        'js'  : 'application/javascript',
        'css' : 'text/css',
        'json': 'application/json',
        'png' : 'image/png',
        'jpg' : 'image/jpeg',
        'gif' : 'image/gif',
        'txt' : 'text/plain',
        'avi' : 'video/x-msvideo'
    }
    return mimedic[filename.split('.')[-1]]


def gethostip():
    '''返回本机IP'''
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(('8.8.8.8', 53))
        ip = s.getsockname()[0]
    finally:
        s.close()
    return ip

class messageBoard:
    def __init__(self):
        self.message = ''
    def update(self, data):
        self.message = data.decode()
    def get(self):
        return self.message.replace('\n', '<br />').encode()

class myHandler(BaseHTTPRequestHandler):
    messages = messageBoard()
    
    def do_send(self, content, type_):
        self.send_response(200)
        self.send_header('Content-Length', len(content))
        self.send_header('Content-Type', type_)
        self.end_headers()
        self.wfile.write(content)
        
    def do_GET(self):
        if self.path == '/':
            filename = 'punch-in.html'
        else:
            self.send_error(404)
            return

        try:
            with open(filename, 'rb') as file:
                content = file.read()
                self.do_send(content, mime(filename))
        except IOError:
            self.send_error(404)

    def do_POST(self):
        # print(repr(self.rfile.read(int(self.headers['content-length']))))
        if self.path == '/hostip':
            self.do_send(gethostip().encode(), 'text/plain; charset=utf-8')
        elif self.path == '/punch-in':
            data = self.rfile.read(int(self.headers['content-length']))
            self.messages.update(data)
            self.do_send(self.messages.get(), 'text/plain; charset=utf-8')
        elif self.path == '/messageboard/update':
            self.do_send(self.messages.get(), 'text/plain; charset=utf-8')
        else:
            self.send_error(404)

def run(serverClass=ThreadingHTTPServer, handlerClass=myHandler):
    serverAddress = ('', 8000)
    httpd = serverClass(serverAddress, handlerClass)
    httpd.serve_forever()

run()
