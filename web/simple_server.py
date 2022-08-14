# -*- coding: utf-8 -*-
"""
Created on Wed Feb  5 18:23:32 2020

@author: phb
"""

import socket

def handle_GET(connectionSocket, url):
    if url == '/':
        file = open('timer.html', 'rb')
        respond_content = file.read()
        respond_header = (
        'HTTP/1.1 200 OK\r\n'
        'Connection: close\r\n'
        'Content-Length: %s\r\n'
        'Content-Type: text/html\r\n\r\n') % (len(respond_content), )
        respond = respond_header.encode() + respond_content
        connectionSocket.send(respond)
        connectionSocket.close()
        file.close()

serverPort = 8080
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
print('The sever is ready, port %d' % (serverPort, ))
connectionSocket, addr = serverSocket.accept()
print('The client %s:%s is connected' %addr)
receive = connectionSocket.recv(2048)

request = receive.decode().split('\r\n')[0].split(' ')
method = request[0]
url = request[1]
if method == 'GET':
    handle_GET(connectionSocket, url)