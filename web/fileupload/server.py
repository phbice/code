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

class myHandler(BaseHTTPRequestHandler):
    def do_send(self, content, type_):
        self.send_response(200)
        self.send_header('Content-Length', len(content))
        self.send_header('Content-Type', type_)
        self.end_headers()
        self.wfile.write(content)
        
    def do_GET(self):
        if self.path == '/':
            filename = 'uploaddemo.html'
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
        if self.path == '/file_upload':
            length = int(self.headers['content-length'])
            with open('uploaded_file', 'wb') as uploaded_file:
                while length > 4096:
                    uploaded_file.write(self.rfile.read(4096))
                    length -= 4096
                uploaded_file.write(self.rfile.read(length))
            self.do_send('Success'.encode(), 'text/plain; charset=utf-8')
        else:
            self.send_error(404)

def run(serverClass=ThreadingHTTPServer, handlerClass=myHandler):
    serverAddress = ('', 8000)
    httpd = serverClass(serverAddress, handlerClass)
    httpd.serve_forever()

run()
